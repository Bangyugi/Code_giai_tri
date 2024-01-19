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
    ll n;
    cin >> n;
    ll sum = 0;
    ll allSum = n * (n + 1) / 2;
    for (int i = 1; i < n;i++)
    {
        int x;
        cin >> x;
        sum += x;
    }
    cout << allSum - sum;
    return 0;
}