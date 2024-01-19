#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int u = 1;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            u = n / i;
            break;
        }
    }
    int a = u;
    int b = (n / u - 1) * u;
    cout << a << " " << b;
}