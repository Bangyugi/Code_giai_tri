#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s, t;
    while (n--)
    {
        cin >> s >> t;
        string word;
        word = s + t;
        sort(word.begin(),word.end());
        // cout << "-" << word << " ";
        for (int i = 0; i < s.size(); i++)
        {
            cout << word[i];
        }
        cout << endl;
    }
}