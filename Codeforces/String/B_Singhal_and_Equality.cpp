#include <bits/stdc++.h>
using namespace std;

int freq[27], n;

int solve(int x)
{
    int cnt = 0, max_val = 0;
    for (int i = 0; i < 27; i++)
    {
        if (cnt == n)
            break;
        if (x <= freq[i])
        {
            cnt += x;
        }
        else
        {
            cnt = cnt + freq[i] + (x - freq[i]);
            max_val += (x - freq[i]);
        }
    }
    if (cnt == n)
        return max_val;
    else
        return INT_MAX;
}

void sol(string s)
{
    n = s.size();
    memset(freq, 0, sizeof freq);
    for (auto x : s)
    {
        freq[x - 'a']++;
    }
    sort(freq, freq + 27, greater<>());
    int ans = INT_MAX;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            ans = min({ans, solve(i), solve(n / i)});
        }
    }
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
        sol(s);
    }
}