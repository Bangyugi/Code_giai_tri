#include <bits/stdc++.h>
using namespace std;

int MOD = 1000000007;

bool isReverse(string s)
{
	string t = s;
	reverse(s.begin(), s.end());
	if (t == s)

		return true;
	else
		return false;
}

long long solve_1(string s)
{
	long long ans = 1;
	multiset<int> se;
	for (int i = 0; i <= ((double)s.size() / 2); i++)
	{
		if (se.empty())
		{
			se.insert(s[i]);
		}
		else
		{
			if (!se.count(s[i]))
			{
				ans *= (se.size() + 1) % MOD;
				ans %= MOD;
				se.clear();
			}
			se.insert(s[i]);
			while (se.count(s[i + 1]))
			{
				se.insert(s[i]);
				i++;
			}
		}
	}
	ans *= (se.size() + 1) % MOD;
	ans %= MOD;
	return ans;
}

long long solve_2(string s)
{
	long long cnt1 = 0, cnt2 = 0;
	int i = 1;
	char c = s[0];
	while (i < s.size())
	{
		if (s[i] == s[i - 1])
		{
			cnt1++;
			i++;
		}
		else
		{
			cnt1++;
			break;
		}
	}
	s.erase(0, i);
	int j = s.size() - 2;
	if (s[j + 1] == c)
	{
		while (j >= 0)
		{
			if (s[j] == s[j + 1])
			{
				cnt2++;
				j--;
			}
			else
			{
				cnt2++;
				break;
			}
		}
		s.erase(j + 1);
	}
	else
	{
		// cout << s << endl;
		return 0;
	}
	// cout << s << endl;
	if (cnt1 > cnt2)
	{
		swap(cnt1, cnt2);
	}
	if (!isReverse(s))
		return 0;
	long long temp = max(1ll * 0, ((cnt1 % MOD * 3) % MOD - (cnt2 % MOD * 2) % MOD + 1) % MOD);
	return (temp % MOD * solve_1(s) % MOD) % MOD;
}

int main()
{
	int t;
	cin >> t;
	cin.ignore();
	while (t--)
	{
		string s;
		getline(cin, s);
		if (isReverse(s))
			cout << solve_1(s) << endl;

		else
			cout << solve_2(s) << endl;
	}
}