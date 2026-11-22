#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int w, h;
    cin >> w >> h;
    long long izlaz = 1;
    long long mod = 998244353;
    int cnt = w + h;
    while(cnt--)
    {
        izlaz = (izlaz*2) % mod;
    }
    cout << izlaz;
    return 0;
}
