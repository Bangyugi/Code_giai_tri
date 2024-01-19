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
    vector<int> children;
    vector<int> survivors;
    for (int i = 1; i <= n; i++)
    {
        children.push_back(i);
    }
    while (children.size() > 1)
    {
        for (int i = 0; i < children.size();i++)
        {
            if (i%2==1)
            {
                cout << children[i] << " ";
            }
            else
            {
                survivors.push_back(children[i]);
            }
        }
        if ((int)children.size()%2==0)
        {
            children = survivors;
        }
        else
        {
            children.clear();
            children.push_back(survivors.back());
            survivors.pop_back();
            for(auto x: survivors)
            {
                children.push_back(x);
            }
        }
            survivors.clear();
    }
        cout << children[0];

    return 0;
}