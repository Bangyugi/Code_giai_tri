#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
using namespace std;
ll MOD = 1e9 + 7;

bool cmp(ii a, ii b)
{
    return a.second < b.second;
}

int main()
{
    // ios_base::sync_with_stdio(NULL);
    // cin.tie(0);
    // cout.tie(0);
    int n;
    cin >> n;
    vector<ii> timeLines;
    for (int i = 0; i < n; i++)
    {
        int s, e;
        cin >> s >> e;
        timeLines.push_back({s, e});
    }
    sort(timeLines.begin(), timeLines.end(), cmp);

    int startTime = timeLines[0].first;
    int finishTime = timeLines[0].second;
    int cnt = 1;
    for (int i = 1; i < n; i++)
    {
        if (timeLines[i].first >= finishTime)
        {
            cnt++;
            finishTime = timeLines[i].second;
        }
    }
    cout << cnt;

    return 0;
}