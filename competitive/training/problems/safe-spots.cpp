#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, K;
    cin >> N >> K;
    int niz[N+2*K] = {0};
    for(int i = K; i < N+K; i++)
    {
        cin >> niz[i];
    }
    int l = niz[0];
    int zbir = 0;
    int d = niz[2*K+1];
    int indTren = K+1;
    for(int i = K; i <= 2*K; i++)
    {
        zbir += niz[i];
    }
    int cnt = 0;
    if(zbir < 2 && niz[K] != 1) cnt++;
    for(int i = 1; i < N; i++)
    {
        zbir = zbir - l + d;
        l = niz[i];
        d = niz[2*K+1+i];
        if(zbir < 2 && niz[K+i] != 1)
        {
           cnt++;
        }
    }
    cout << cnt;

    return 0;
}
