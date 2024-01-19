#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
using namespace std;
ll MOD = 1e9 + 7;

int main()
{
    //ios_base::sync_with_stdio(NULL);
    //cin.tie(0);
    //cout.tie(0);
    int n;
    cin >> n;
    while(n--)
    {
        string s;
        cin >> s;
        if (s.size()>10)
        {
            cout << s[0] << (s.size() - 2) << s[s.size() - 1] << endl;
        }
        else
        {
            cout << s << endl;
        }
    }
    return 0;
}