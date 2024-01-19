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
    vector<string> gray;
    gray.push_back("0");
    gray.push_back("1");
    for (int i = 2; i <= n; i++)
    {
        int size = gray.size();
        for (int i = size - 1; i >= 0; i--)
        {
            gray.push_back(gray[i]);
        }
        for (int i = 0; i < size;i++)
        {
            gray[i] = "0" + gray[i];
            gray[size + i] = "1" + gray[size + i];
        }
    }
    for (auto x: gray)
    {
        cout << x << endl;
    }
    return 0;
}