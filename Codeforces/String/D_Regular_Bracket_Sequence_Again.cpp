#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;

        // Sử dụng lập trình động để đếm số dãy dấu ngoặc hợp lệ đặc biệt
        vector<int> dp(N + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= N; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                dp[i] = (dp[i] + (1LL * dp[j] * dp[i - 1 - j]) % MOD) % MOD;
            }
        }

        // Trừ đi số dãy dấu ngoặc chu kỳ N
        int ans = dp[N];
        for (int k = 1; k <= N / 2; ++k)
        {
            ans = (ans - (1LL * dp[k] * dp[N - k]) % MOD + MOD) % MOD;
        }

        cout << "So ngoac hop le la: " << ans << "\n";
    }

    return 0;
}
