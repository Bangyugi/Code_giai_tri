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
    if (n>2 && n%2==0)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}