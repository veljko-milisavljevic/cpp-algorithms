#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    int nizX[N+1] = {0};
    int nizY[N+1] = {0};
    int cntX = 0;
    int cntY = 0;
    int x,y;
    long long zbir = 0;
    while(M--)
    {
        cin >> x >> y;

        if(nizX[x] == 0) //Do sada nema krompira u datom redu
        {
            nizX[x] = 1;
            cntX++;
            zbir += (long long) N - cntY;
        }

        if(nizY[y] == 0) //Do sada nema krompira u datoj koloni
        {
            nizY[y] = 1;
            cntY++;
            zbir += (long long) N - cntX;
        }

    }
    cout << zbir;
    return 0;
}
