#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
using namespace std;
ll MOD = 1e9 + 7;

int main()
{
    // ios_base::sync_with_stdio(NULL);
    // cin.tie(0);
    // cout.tie(0);
    string s;
    cin >> s;
    ll longestValue = 1;
    ll value = 1;

    for (int i = 1; i < (int)s.size(); i++)
    {
        if (s[i] != s[i - 1])
        {
            longestValue = max(longestValue, value);
            value = 1;
        }
        else
        {
            value++;
        }
    }
    longestValue = max(longestValue, value);
    cout << longestValue;
    return 0;
}