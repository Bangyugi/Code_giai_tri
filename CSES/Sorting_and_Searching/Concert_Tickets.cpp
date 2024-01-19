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
    ll n, m;
    cin >> n >> m;
    vector<ll> priceOfEachTicket(n);
    vector<ll> orderOfCustomer(m);
    multiset<ll> mse;
    for (int i = 0; i < n; i++)
    {
        cin >> priceOfEachTicket[i];
        mse.insert(priceOfEachTicket[i]);
    }

    for (int i = 0; i < m; i++)
    {
        cin >> orderOfCustomer[i];
    }
    for (int i = 0; i < m; i++)
    {
        auto it = mse.upper_bound(orderOfCustomer[i]);
        if (it == mse.begin())
        {
            cout << -1 << endl;
        }
        else
        {
            cout << *(--it) << endl;
            mse.erase(it);
        }
    }

    return 0;
}