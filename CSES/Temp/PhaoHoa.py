import pygame
from random import randint, uniform, choice
import math

vector2 = pygame.math.Vector2
trails = []

GRAVITY_FIREWORK = vector2(0, 0.3)
GRAVITY_PARTICLE = vector2(0, 0.07)
DISPLAY_WIDTH = 600
DISPLAY_HEIGHT = 900
BACKGROUND_COLOR = (20, 20, 30)
FIREWORK_SPEED_MIN = 17
FIREWORK_SPEED_MAX = 20
FIREWORK_SIZE = 4
PARTICLE_LIFESPAN = 70
X_SPREAD = 0.8
Y_SPREAD = 0.8
PARTICLE_SIZE = 2
MIN_PARTICLES = 100
MAX_PARTICLES = 400
X_WIGGLE_SCALE = 20
Y_WIGGLE_SCALE = 10
EXPLOSION_RADIUS_MIN = 18
EXPLOSION_RADIUS_MAX = 34
COLORFUL = True
TRAIL_LIFESPAN = PARTICLE_LIFESPAN / 2
TRAIL_FREQUENCY = 10
TRAILS = True

class Text:
    def __init__(self, text, font, size, color, x, y):
        self.font = pygame.font.SysFont(font, size)
        self.text = text
        self.color = color
        self.x = x
        self.y = y

    def draw(self, win):
        rendered_text = self.font.render(self.text, True, self.color)
        text_rect = rendered_text.get_rect(center=(self.x, self.y))
        win.blit(rendered_text, text_rect)

def create_gradient_color(start_color, end_color, percent):
    r = start_color[0] + int((end_color[0] - start_color[0]) * percent)
    g = start_color[1] + int((end_color[1] - start_color[1]) * percent)
    b = start_color[2] + int((end_color[2] - start_color[2]) * percent)
    return (r, g, b)

class Firework:
    def __init__(self):
        self.colour = tuple(randint(0, 255) for _ in range(3))
        self.colours = tuple(tuple(randint(0, 255) for _ in range(3)) for _ in range(3))
        self.firework = Particle(randint(50, DISPLAY_WIDTH), DISPLAY_HEIGHT-100, True, self.colour)
        self.exploded = False
        self.particles = []

    def update(self, win: pygame.Surface) -> None:
        if not self.exploded:
            self.firework.apply_force(GRAVITY_FIREWORK)
            self.firework.move()
            self.show(win)
            if self.firework.vel.y >= 0:
                self.exploded = True
                self.explode()

        else:
            for particle in self.particles:
                particle.update()
                particle.show(win)

    def explode(self):
        amount = randint(MIN_PARTICLES, MAX_PARTICLES)
        if COLORFUL:
            self.particles = [Particle(self.firework.pos.x, self.firework.pos.y, False, choice(self.colours)) for _ in range(amount)]
        else:
            self.particles = [Particle(self.firework.pos.x, self.firework.pos.y, False, self.colour) for _ in range(amount)]

    def show(self, win: pygame.Surface) -> None:
        x = int(self.firework.pos.x)
        y = int(self.firework.pos.y)
        pygame.draw.circle(win, self.colour, (x, y), self.firework.size)

    def remove(self) -> bool:
        if not self.exploded:
            return False

        for p in self.particles:
            if p.remove:
                self.particles.remove(p)

        return len(self.particles) == 0

class Particle(object):
    def __init__(self, x, y, firework, colour):
        self.firework = firework
        self.pos = vector2(x, y)
        self.origin = vector2(x, y)
        self.acc = vector2(0, 0)
        self.remove = False
        self.explosion_radius = randint(EXPLOSION_RADIUS_MIN, EXPLOSION_RADIUS_MAX)
        self.life = 0
        self.colour = colour
        self.trail_frequency = TRAIL_FREQUENCY + randint(-3, 3)

        if self.firework:
            self.vel = vector2(0, -randint(FIREWORK_SPEED_MIN, FIREWORK_SPEED_MAX))
            self.size = FIREWORK_SIZE
        else:
            self.vel = vector2(uniform(-1, 1), uniform(-1, 1))
            self.vel.x *= randint(7, self.explosion_radius + 2)
            self.vel.y *= randint(7, self.explosion_radius + 2)
            self.size = randint(PARTICLE_SIZE - 1, PARTICLE_SIZE + 1)
            self.move()
            self.outside_spawn_radius()

    def update(self) -> None:
        self.life += 1
        if self.life % self.trail_frequency == 0:
            trails.append(Trail(self.pos.x, self.pos.y, False, self.colour, self.size))
        self.apply_force(vector2(uniform(-1, 1) / X_WIGGLE_SCALE, GRAVITY_PARTICLE.y + uniform(-1, 1) / Y_WIGGLE_SCALE))
        self.move()

    def apply_force(self, force: pygame.math.Vector2) -> None:
        self.acc += force

    def outside_spawn_radius(self) -> bool:
        distance = math.sqrt((self.pos.x - self.origin.x) ** 2 + (self.pos.y - self.origin.y) ** 2)
        return distance > self.explosion_radius

    def move(self) -> None:
        if not self.firework:
            self.vel.x *= X_SPREAD
            self.vel.y *= Y_SPREAD

        self.vel += self.acc
        self.pos += self.vel
        self.acc *= 0

        self.decay()

    def show(self, win: pygame.Surface) -> None:
        x = int(self.pos.x)
        y = int(self.pos.y)
        pygame.draw.circle(win, self.colour, (x, y), self.size)

    def decay(self) -> None:
        if self.life > PARTICLE_LIFESPAN:
            if randint(0, 15) == 0:
                self.remove = True

        if not self.remove and self.life > PARTICLE_LIFESPAN * 1.5:
            self.remove = True

class Trail(Particle):
    def __init__(self, x, y, is_firework, colour, parent_size):
        Particle.__init__(self, x, y, is_firework, colour)
        self.size = parent_size - 1

    def decay(self) -> bool:
        self.life += 1
        if self.life % 100 == 0:
            self.size -= 1

        self.size = max(0, self.size)
        self.colour = (min(self.colour[0] + 5, 255), min(self.colour[1] + 5, 255), min(self.colour[2] + 5, 255))

        if self.life > TRAIL_LIFESPAN:
            ran = randint(0, 15)
            if ran == 0:
                return True

        if not self.remove and self.life > TRAIL_LIFESPAN * 1.5:
            return True
        
        return False

def update(win, fireworks, trails, happy_new_year_text):
    win.fill(BACKGROUND_COLOR)

    if TRAILS:
        for t in trails:
            t.show(win)
            if t.decay():
                trails.remove(t)

    for fw in fireworks:
        fw.update(win)
        if fw.remove():
            fireworks.remove(fw)

        if fw.exploded and len(fw.particles) > 0:
            particle_color = fw.particles[0].colour
            gradient_color = create_gradient_color((255, 255, 255), particle_color, 0.5)
            happy_new_year_text.color = gradient_color

    happy_new_year_text.draw(win)
    pygame.display.update()

def main():
    pygame.init()
    pygame.display.set_caption("Fireworks in Pygame")
    win = pygame.display.set_mode((DISPLAY_WIDTH, DISPLAY_HEIGHT))
    clock = pygame.time.Clock()

    fireworks = [Firework() for i in range(1)]
    running = True

    happy_new_year_text = Text("Happy New Year", 'Comic Sans MS', 40, (255, 255, 255), DISPLAY_WIDTH // 2, DISPLAY_HEIGHT // 1.4)

    while running:
        clock.tick(60)
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
            elif event.type == pygame.KEYDOWN:
                if event.key == pygame.K_1:
                    fireworks.append(Firework())
                elif event.key == pygame.K_2:
                    for i in range(10):
                        fireworks.append(Firework())

        win.fill(BACKGROUND_COLOR)

        if randint(0, 70) == 1:
            fireworks.append(Firework())

        update(win, fireworks, trails, happy_new_year_text)

    pygame.quit()
    quit()

if __name__ == "__main__":
    main()
