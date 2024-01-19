#include <bits/stdc++.h>
using namespace std;

int MOD = 1000000007;

void solve_1(string s)
{
    long long ans = 1;
    multiset<int> se;
    for (int i = 0; i < s.size(); i++)
    {
        if (se.empty())
        {
            se.insert(s[i]);
        }
        else
        {
            if (!se.count(s[i]))
            {
                ans *= (se.size() + 1) % MOD;
                ans %= MOD;
                se.clear();
            }
            se.insert(s[i]);
        }
    }
    ans *= (se.size() + 1) % MOD;
    ans %= MOD;
    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string s;
        getline(cin, s);
        solve_1(s);
    }
}