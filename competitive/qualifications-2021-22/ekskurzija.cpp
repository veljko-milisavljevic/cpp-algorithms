#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--)
    {
        long long N, M, K;
        cin >> N >> M >> K;
        long long bananica = (N % K) * (N/K+1) * (N/K+2) / 2 + (K - N % K) * (N / K) * (N / K + 1) / 2;
        if(bananica <= M) cout << "Tak\n";
        else cout << "Nie\n";
    }

    return 0;
}
