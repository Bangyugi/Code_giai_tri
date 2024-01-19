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

    int n;
    cin >> n;
    if (n == 1)
    {
        cout << 1;
    }
    else if (n >= 4)
    {
        for (int i = 2; i <= n; i += 2)
        {
            cout << i << " ";
        }
        for (int i = 1; i <= n; i += 2)
        {
            cout << i << " ";
        }
    }
    else
    {
        cout << "NO SOLUTION";
    }
    return 0;
}