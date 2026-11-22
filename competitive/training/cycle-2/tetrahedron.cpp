#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    long long mod = 1000000007;
    long long stepeni_trojke[n+1] = {0};
    stepeni_trojke[0] = 1;
    long long dp[n+1];
    dp[0] = 1;
    for(int i = 0; i < n; i++)
    {
        stepeni_trojke[i+1] = (stepeni_trojke[i]*3) % mod;
        dp[i+1] = (stepeni_trojke[i] - dp[i]) % mod;
    }
    if(dp[n] >= 0) cout << dp[n];
    else cout << dp[n] + mod;

    return 0;
}
