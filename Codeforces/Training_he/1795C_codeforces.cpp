#include <bits/stdc++.h>

using namespace std;

using li = long long;

int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        int n;
        cin >> n;
        vector<long long> a(n);
        vector<long long> b(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        vector<long long> sum(n + 1);
        for (int i = 0; i < n; i++)
        {
            sum[i + 1] = sum[i] + b[i];
        }
        vector<long long> cnt(n + 1);
        vector<long long> add(n + 1);
        for (int i = 0; i < n; i++)
        {
            int j = upper_bound(sum.begin(), sum.end(), a[i] + sum[i]) - sum.begin() - 1;
            cnt[i] += 1;
            cnt[j] -= 1;
            add[j] += a[i] - sum[j] + sum[i];
        }
        // for (int i = 0; i < n; i++)
        // {
        //     cout << a[i] << " ";
        // }
        // cout << endl;
        // for (int i = 0; i < n; i++)
        // {
        //     cout << b[i] << " ";
        // }
        // cout << endl;
        // for (auto x : sum)
        // {
        //     cout << x << " ";
        // }
        // cout << endl;
        // for (auto x : cnt)
        // {
        //     cout << x << " ";
        // }
        // cout << endl;
        // for (auto x : add)
        // {
        //     cout << x << " ";
        // }
        // cout << endl;
        for (int i = 1; i <= n; i++)
        {
            cnt[i] = cnt[i - 1] + cnt[i];
        }

        // for (auto x : cnt)
        // {
        //     cout << x << " ";
        // }
        // cout << endl;
        for (int i = 0; i < n; ++i)
        {

            cout << cnt[i] * b[i] + add[i] << ' ';
        }
        cout << '\n';
    }
}