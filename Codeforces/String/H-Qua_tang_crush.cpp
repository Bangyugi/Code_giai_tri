#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Hàm tính số ước của một số nguyên
int countDivisors(long long n) {
    int count = 0;
    for (long long i = 1; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            if (n / i == i) {
                ++count;
            } else {
                count += 2;
            }
        }
    }
    return count;
}

int main() {
    long long n;
    cin >> n;

    // Đặc trưng của bài toán là cần tính số ước của n và ước chung lớn nhất của các số ước của n
    // Sau đó, kết quả sẽ là số ước chung lớn nhất đó
    int divisors = countDivisors(n);

    // Tìm ước chung lớn nhất của các số ước của n
    for (int i = 2; i <= divisors; ++i) {
        while (divisors % i == 0 && n % i == 0) {
            divisors /= i;
            n /= i;
        }
    }

    cout << divisors << endl;

    return 0;
}
