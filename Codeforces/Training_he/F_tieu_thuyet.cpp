#include <iostream>
#include <vector>
#include <algorithm>

// Cho một cuốn tiểu thuyết gồm n chương, chương thứ i có a[i] trang, (1≤i≤n), nếu in thành một cuốn sách thì quá dày, 
// vì vậy người ta quyết định in thành k tập, mỗi chương phải nằm gọn trong một tập.

// Tập 1 bao gồm một số chương đầu tiên, mỗi tập tiếp theo bao gồm một số chương tiếp, theo đúng trình tự như in tất 
// cả các chương liên tiếp thành một cuốn. Ban biên tập phải có nhiệm vụ phân chia sao cho số trang của tập dày nhất 
// là ít nhất.

// Ví dụ, với n=5, số trang trong mỗi chương tương ứng lần lượt là 3, 7, 12, 8, 5 và dự kiến in thành 3 tập thì tập 1 
// sẽ chứa chương 1 và 2 với tổng số trang là 10, tập 2 chứa chương 3 với tổng số trang là 12, tập 3 chứa hai chương 
// cuối với tổng số trang là 13. Như vậy, tập dày nhất có số trang là 13  và đây cũng là cách phân chia phù hợp với 
// yêu cầu đã nêu. Hãy xác định số trang của tập dày nhất nhận được sau kết quả làm việc của ban biên tập.

// Input
// Dòng đầu tiên chứa 2 số nguyên n và k (1≤k≤n≤105)
// Dòng thứ 2 chứa n số nguyên a1,a2,...,an(1≤ai≤109), (1≤i≤n)

// Output
// Đưa ra màn hình một số nguyên – số trang của tập dày nhất.

// Example
// input
// 5 3
// 3 7 12 8 5
// output
// 13

using namespace std;

// Hàm kiểm tra xem có thể chia các chương thành k tập sao cho số trang của tập dày nhất không vượt quá max_pages
bool check(const vector<int> &a, int n, int k, int max_pages)
{
    int cnt = 1;
    int pages = 0;
    for (int i = 0; i < n; i++)
    {
        pages += a[i];
        if (pages > max_pages)
        {
            cnt++;
            pages = a[i];
        }
    }
    return cnt <= k;
}

// Hàm tìm số trang của tập dày nhất bằng phương pháp nhị phân
int binarySearchMaxPages(const vector<int> &a, int n, int k, int max_val)
{
    int l = max_val;
    int r = 1000000001;

    while (l < r)
    {
        int mid = l + (r - l) / 2;
        if (check(a, n, k, mid))
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    return l;
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    int max_val = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        max_val = max(max_val, a[i]);
    }

    int res = binarySearchMaxPages(a, n, k, max_val);
    cout << res ;

    return 0;
}
