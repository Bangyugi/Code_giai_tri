#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
using namespace std;
ll MOD = 1e9 + 7;
vector<ii> children;
vector<ll> removal;

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    children.push_back({0, 0});
    for (int i = 1; i <= n; i++)
    {
        children.push_back({i,0});
    }
  
    int dem = 0;
    while (removal.size() != n)
    {
        for (int i = 1; i < children.size(); i++)
        {
            if (children[i].second==0)
            {
                if (dem==k)
                {
                    children[i].second = 1;
                    removal.push_back(children[i].first);
                    dem = 0;
                }
                else
                {
                    dem++;
                }

            }
        }
    }
    for(auto x: removal)
    {
        cout << x << " ";
    }
    // while (children.size() > 1)
    // {
    //     if (children.size() > k)
    //     {
    //         for (i = 0; i < children.size(); i++)
    //         {
    //             if ((i + 1) % (k + 1) == 0)
    //             {
    //                 cout << children[i] << " ";
    //             }
    //             else
    //             {
    //                 survivors.push_back(children[i]);
    //             }
    //         }

    //     }
    // }

    return 0;
}