#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
using namespace std;
ll MOD = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);
    int l, n;
    cin >> l >> n;
    multiset<int> length;
    length.insert(l-0);
    set<int> position;
    position.insert(0);
    position.insert(l);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        position.insert(x);
        auto it =position.find(x);
        int preValue = *prev(it);
        int nextValue = *next(it);
        length.erase(length.find(nextValue - preValue));
        length.insert(x - preValue);
        length.insert(nextValue - x);
        cout << *length.rbegin() << " ";
    }

    return 0;
}