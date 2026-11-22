#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, K;
    cin >> N >> K;
    int indeksi[N+1]; //Niz indeksa
    int spil[N+1];
    int a;
    for(int i = 1; i <= N; i++)
    {
        cin >> a;
        indeksi[a] = i;
        spil[i] = a;
    }
    if(indeksi[K] == N)
    {
        cout << spil[1];
    }
    else
    {
        cout << spil[indeksi[K] + 1];
    }
    return 0;
}
