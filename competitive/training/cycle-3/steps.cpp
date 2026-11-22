#include <bits/stdc++.h>

using namespace std;

const long long mod = 1000000007;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    long long dp[N+1];
    long long pref[N+1];

    dp[0] = 1;
    pref[0] = 1;

    for(int i = 1; i <= N; i++)
    {
        if(i <= M)
        {
            dp[i] = pref[i-1];
        }
        else
        {
            dp[i] = (pref[i-1] - pref[i-M-1]);
            if(dp[i] < 0) dp[i] += mod;
        }
        pref[i] = (pref[i-1] + dp[i]) % mod;
    }
    cout << dp[N];

    return 0;
}
