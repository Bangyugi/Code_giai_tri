#include <bits/stdc++.h>
using namespace std;


void solve_2(string s, int i)
{
    for (int j = i; j < s.size(); j = j + i + 1)
    {
        s.insert(j, " ");
    }
    // cout << s << endl;
    stringstream ss(s);
    string number;
    vector<int> v;
    while (ss >> number)
    {
        v.push_back(stoi(number));
    }
    // for (auto x : v)
    // {
    //     cout << x << " ";
    // }
    // cout << endl;

    if (v.size() > 1)
    {
        bool check = true;
        for (int i = 1; i < v.size(); i++)
        {
            if (v[i] <= v[i - 1] || v[i] - v[i - 1] > 2)
            {
                check = false;
                break;
            }
        }
        if (check)
        {
            int temp = v[0];
            for (int i = 1; i < v.size(); i++)
            {
                temp++;
                if (v[i] != temp)
                {
                    cout << temp << endl;
                    break;
                }
            }
        }
        // else
        // {
        //     cout << -1 << endl;
        // }
    }
}

void solve_1(string s)
{
    int n = s.size();
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            solve_2(s, i);
            if (n / i != i && i != 1)
                solve_2(s, n / i);
        }
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;
        if (s.size() == 1)
        {
            cout << -1 << endl;
        }
        else
            solve_1(s);
    }
    return 0;
}
