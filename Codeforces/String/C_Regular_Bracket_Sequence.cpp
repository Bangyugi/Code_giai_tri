#include <bits/stdc++.h>
using namespace std;

void sol(string s, int a, int b)
{
    long long cnt = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            cnt++;
        }
        else if (s[i] == ')')
        {
            cnt--;
        }
    }
    long long costa = 0, costb = 0, total = 0;
    total += abs(cnt) * a;
    if (cnt > 0)
    {
        for (int i = s.size() - 1; i >= 0;)
        {
            if (cnt == 0)
                break;
            if (s[i] == '(')
            {
                s.erase(i, 1);
                cnt--;
            }
            else
            {
                i--;
            }
        }
    }
    else if (cnt < 0)
    {
        for (int i = 0; i < s.size();)
        {
            if (cnt == 0)
                break;
            if (s[i] == ')')
            {
                s.erase(i, 1);
                cnt++;
            }
            else
            {
                i++;
            }
        }
    }
    // cout << s << endl;
    stack<char> x;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            x.push('(');
        }
        else
        {
            if (x.empty())
            {
                costa = 2 * a;
                costb = b;
                total += min(costa, costb);
            }
            else
            {
                x.pop();
            }
        }
        cnt++;
    }

    cout << total << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, a, b;
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        cin >> n >> a >> b;
        string s;
        cin >> s;
        sol(s, a, b);
    }
}
