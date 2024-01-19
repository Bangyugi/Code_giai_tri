#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n;
    string ques;
    cin >> ques;
    cin >> m;
    string a[m];
    vector<int> rightAns(m);
    vector<int> wrongAns(m);
    multiset<pair<int, int>> se;
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == ques[j])
            {
                rightAns[i]++;
            }
            else
            {
                wrongAns[i]++;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        // cout << i << " " << rightAns[i] << " " << wrongAns[i] << endl;
    }

    for (int i = 1; i < m; i++)
    {

        for (int j = 0; j < i; j++)
        {
            // cout <<j+1<<" "<< rightAns[j] << " " << wrongAns[j] << endl;
            // cout <<i+1<<" "<< rightAns[i] << " " << wrongAns[i] << endl;
            int sameAns = 0;
            int sameRightAns = 0;
            int sameWrongAns = 0;
            for (int k = 0; k < n; k++)
            {
                if (a[i][k] == a[j][k])
                {
                    sameAns++;
                    if (a[i][k] == ques[k])
                    {
                        sameRightAns++;
                    }
                }
                sameWrongAns = sameAns - sameRightAns;
            }
            // cout << sameAns << " " << sameRightAns << " " << sameWrongAns << endl;
            if (sameRightAns > rightAns[i] / 2 && sameRightAns > rightAns[j] / 2 && sameWrongAns > wrongAns[i] / 2 && sameWrongAns > wrongAns[j] / 2)
            {
                se.insert({j + 1, i + 1});
            }
        }
    }
    cout << se.size() << endl;
    for (auto x : se)
    {
        cout << x.first << " " << x.second << endl;
    }
}
