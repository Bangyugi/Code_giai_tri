#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int mua, ban;
    for (int i = 1; i <= 100000000; i++)
    {
        int x = upper_bound(a.begin(), a.end(), i) - a.begin() - 1;
        ban = x + 1;
        x = lower_bound(b.begin(), b.end(), i) - b.begin();
        mua = m - x;
        if (ban >= mua)
        {
            cout << i;
            return 0;
        }
    }
}