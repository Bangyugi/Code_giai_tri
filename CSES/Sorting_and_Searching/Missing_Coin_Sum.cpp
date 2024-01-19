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
    ll a[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];

    }
    sort(a, a + n);
    // note: các số có thể tạo được là môt tập hợp {a,b} với a là số nhỏ nhất và b là số lớn nhất
    // a: là phần tử mà ta xét tới 
    // b: tổng các phần tử đứng trước nó và nó
    ll sum = 0;
    for (ll i = 0; i < n;i++)
    {
        if (sum+1<a[i])
        {
           break;
        }
        else
        {
            sum += a[i];
        }
    }
    cout << sum + 1 << endl;
    return 0;
}