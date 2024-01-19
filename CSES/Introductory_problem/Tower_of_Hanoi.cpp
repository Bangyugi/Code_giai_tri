#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
using namespace std;
ll MOD = 1e9 + 7;

void towerOfHanoi(int n, int a, int b, int c)
{
    if (n == 0)
        return;
    towerOfHanoi(n - 1, a, c, b);
    cout << a << " " << c << endl;
    towerOfHanoi(n - 1, b, a, c);
}

int main()
{
    // ios_base::sync_with_stdio(NULL);
    // cin.tie(0);
    // cout.tie(0);
    int n;
    cin >> n;
    cout << pow(2, n) - 1 << endl;
    towerOfHanoi(n, 1, 2, 3);
    return 0;
}