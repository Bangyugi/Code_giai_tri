#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
using namespace std;
ll MOD = 1e9 + 7;


int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> value(n + 1);
    vector<int> position(n+1);
    for (int i = 1; i <= n; i++)
    {
        cin >> value[i];
        position[value[i]] = i;
    }
    // sort(position.begin() + 1, position.end());

    while (q--)
    {
        int a, b;
        cin >> a >> b;
        swap(value[a], value[b]);
        swap(position[value[a]], position[value[b]]);
        int ans = 1;
        for (int i = 2; i <= n;i++)
        {
            if (position[i]<position[i-1])
            {
                ans++;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}