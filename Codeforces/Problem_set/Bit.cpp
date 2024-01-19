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
    int X = 0;
    while (n--)
    {
        string s;
        cin >> s;
        if (s[1]=='+')
        {
            X++;
        }
        else
        {
            X--;
        }
    }
    cout << X;

    return 0;
}