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
    map<char, int> mp;
    for (int i = 0; i < (int)s.size(); i++)
    {
        mp[s[i]]++;
    }
    int cnt = 0;
    for (auto x : mp)
    {
        if (x.second % 2 == 1)
        {
            cnt++;
            if (cnt > 1)
            {
                cout << "NO SOLUTION\n";
                return 0;
            }
        }
    }
    string str1 = "";
    string str2 = "";
    for (auto x : mp)
    {
        if (x.second % 2 == 0)
        {
            int temp = x.second / 2;
            while (temp--)
            {
                str1 += x.first;
            }
        }
        else
        {
            int temp = x.second;
            while (temp--)
            {
                str2 += x.first;
            }
        }
    }
    string temp = str1;
    reverse(str1.begin(), str1.end());
    cout << temp + str2 + str1;
    return 0;
}