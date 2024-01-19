#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
using namespace std;
ll MOD = 1e9 + 7;
bool final = false;

void strGenerate(string &s)
{
    int n = s.size()-1;
    int i = n - 1;
    while (i >= 0 && s[i] >= s[i + 1])
    {
        i--;
    }
    if (i == -1)
    {
        final = true;
    }
    else
    {
        int j = n;
        while (s[i] >= s[j])
        {
            j--;
        }
        swap(s[i], s[j]);
        reverse(s.begin() + i + 1, s.end());
    }
}

int main()
{
    // ios_base::sync_with_stdio(NULL);
    // cin.tie(0);
    // cout.tie(0);
    string s;
    cin >> s;
    vector<string> str;
    sort(s.begin(), s.end());
    while (!final)
    {
        str.push_back(s);
        strGenerate(s);
    }
    cout << str.size() << endl;
    for(auto x: str)
    {
        cout << x << endl;
    }

    return 0;
}