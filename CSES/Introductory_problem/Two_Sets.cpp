#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
using namespace std;
ll MOD = 1e9 + 7;
int d[1000005];

int main()
{
    //ios_base::sync_with_stdio(NULL);
    //cin.tie(0);
    //cout.tie(0);
    ll n;
    cin >> n;
    int cnt = 0;
    ll allSum = n * (n + 1) / 2;
    if (allSum%2==0)
    {
        cout << "YES" << endl;
        ll temp = allSum / 2;
        int i = n;
        while (temp && i>0)
        {
            if (temp-i>=0)
            {
                cnt++;
                temp -= i;
                d[i] = 1;
            }
            i--;
        }
        cout << cnt << endl;
        for (int i = 1; i <= n;i++)
        {
            if (d[i]==1)
            {
                cout << i << " ";
            }
        }
        cout << endl;
        cout << n - cnt << endl;
        for (int i = 1; i <= n;i++)
        {
            if (d[i]==0)
            {
                cout << i << " ";
            }
        }
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}
