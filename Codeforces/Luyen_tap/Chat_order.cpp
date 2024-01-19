#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
using namespace std;
ll MOD = 1e9 + 7;
 
int main()
{
    //ios_base::sync_with_stdio(NULL);
    //cin.tie(0);
    //cout.tie(0);
    int n;
    cin >> n;
    set<string> se;
    vector<string> v;
    for (int i = 0; i < n;i++)
    {
        string s;
        cin >> s;
        se.insert(s);
        v.push_back(s);
    }
    
    for (int i = n-1; i >=0 ;i--)
    {
        auto it = se.find(v[i]);
        if (it!=se.end())
        {
            cout << *it << endl;
            se.erase(it);
        }
    }
        return 0;
}