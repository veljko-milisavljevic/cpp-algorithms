#include <iostream>
#include <algorithm>
#define MAXN 100000
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    int niz[N+2];
    niz[0] = 0;
    niz[N+1] = MAXN;
    for(int i = 1; i <= N; i++)
    {
        cin >> niz[i];
    }
    sort(niz,niz + N+2);
    int razmaci[N];
    int maks = 0;
    int krajnjiIND;
    for(int i = 0; i < N; i++)
    {
        razmaci[i] = niz[i+2] - niz[i];
        if(maks < razmaci[i])
        {
            maks = razmaci[i];
            krajnjiIND = i;
        }
    }
    int pomocni = 0;
    if(krajnjiIND == N-1) pomocni++;
    if(N == 1)
    {
        cout << 100000;
    }
    else if(N == 2)
    {
        cout << maks-(1-pomocni);
    }
    else if(N == MAXN)
    {
        cout << 1;
    }
    else
    {
        cout << maks-(1-pomocni);
    }
    return 0;
}
