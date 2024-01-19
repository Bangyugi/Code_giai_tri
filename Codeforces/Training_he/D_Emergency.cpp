#include <iostream>
#include <vector>
#include <algorithm>

// Trên trạm không gian việc thoát hiểm phức tạp hơn nhiều so với việc thoát hiểm khi có cháy ở các nhà cao tầng
// trên mặt đất. Các nhà nghiên cứu trên trạm phải chạy tới cửa thoát hiểm, mặc áo giáp bảo hộ sau đó di chuyển 
// tới tàu cứu hộ. Hành lang thoát hiểm có thể coi như một đường thẳng. Dọc hành lang có lắp n thùng chứa áo 
// giáp bảo hộ, thùng thứ i ở tọa độ xi và chứa ai bộ áo,(1 <= i <= n). Khi có tín hiệu báo động các thùng áo sẽ 
// tự động tách ra khỏi chổ được lắp và di chuyển về vị trí cửa thoát hiểm. Năng lượng di chuyển các thùng áo 
// giáp tỷ lệ với đường đi và số bộ áo trong thùng. Nói cách khác để di chuyển một thùng áo có a[i] áo ở tọa độ 
// x đến tọa độ y sẽ mất năng lượng là |x - y| * a[i]. Như vậy, để giảm thiểu năng lượng tập kết áo bảo hộ cần 
// chọn vị trí đặt cửa thoát hiểm ở nơi sao cho tất cả áo bảo hộ được tập trung đầy đủ với chi phí năng lượng nhỏ 
// nhất. Hãy xác định vị trí đặt cửa thoát hiểm. Nếu tồn tại nhiều cách chọn - đưa ra cách chọn với tọa độ nhỏ nhất.

// Input
// Dòng đầu tiên chứa số nguyên n (1 ≤ n ≤ 105).

// Dòng thứ 2 chứa n số nguyên a1,a2,...,an (1 ≤ ai ≤ 1000000, (1 ≤ i ≤ n)).

// Dòng thứ 3 chứa n số nguyên x1,x2,...,xn (1 ≤ xi ≤ 1000000, xi < xi+1, (1 ≤ i ≤ n)).

// Output
// In ra một số nguyên - tọa độ cửa thoát hiểm.

// Example
// inputCopy
// 4
// 1 4 1 1
// 1 2 3 4
// outputCopy
// 2
// chỉ ra thuật toán và Giải quyết bài toán trên bằng C++

using namespace std;

// Hàm tính tổng năng lượng di chuyển khi đặt cửa thoát hiểm tại vị trí x
long long calculateTotalEnergy(vector<int>& a, vector<int>& x, int n, int door_position) {
    long long total_energy = 0;
    for (int i = 0; i < n; i++) {
        total_energy += (long long)(abs(x[i] - x[door_position])) * a[i];
    }
    return total_energy;
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n); // Số lượng áo trong từng thùng
    vector<int> x(n); // Tọa độ của từng thùng
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    // Sử dụng binary search để tìm vị trí cửa thoát hiểm tối ưu
    int left = 0;
    int right = n - 1;
    while (left < right) {
        int mid = (left + right) / 2;
        long long energy_left = calculateTotalEnergy(a, x, n, mid);
        long long energy_right = calculateTotalEnergy(a, x, n, mid + 1);

        if (energy_left <= energy_right) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    cout << x[left] << endl;

    return 0;
}
