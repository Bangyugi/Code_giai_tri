#include <bits/stdc++.h>
using namespace std;

long long luythua(long long a, long long b)
{
    if (b == 0)
    {
        return 1;
    }
    long long res = luythua(a, b / 2);
    if (b % 2 == 0)
    {
        return res * res;
    }
    else
    {
        return res * res * a;
    }
}

int main()
{
    int a, x, m;
    cin >> a >> x >> m;
    long long res = 0;
    for (int i = 0; i <= x - 1; i++)
    {
        res += luythua(a, i) % m;
        res %= m;
    }
    cout<<res;
}