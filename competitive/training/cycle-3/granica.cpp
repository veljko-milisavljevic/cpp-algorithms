#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    int M[N];
    for(int i = 0; i < N; i++)
    {
        cin >> M[i];
    }
    int NZD = abs(M[0]- M[1]);
    for(int i = 0; i < N-1; i++)
    {
        for(int j = i+1; j < N; j++)
        {
            NZD = __gcd(NZD, abs(M[i]- M[j]));
        }
    }

    for(int i = 2; i*i <= NZD; i++)
    {
        if(NZD % i == 0)
        {
            if(NZD / i == i) cout << i << " ";
            else cout << i << " " << NZD / i << " ";
        }
    }
    cout << NZD;

    return 0;
}
