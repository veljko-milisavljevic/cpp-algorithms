#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    int niz[N];
    long long ost[3] = {0}; //???
    for(int i = 0; i < N; i++)
    {
        cin >> niz[i];
        ost[niz[i] % 3]++;
    }
    long long cnt = 0;
    cnt += (long long)ost[1]*ost[2] + (ost[0] * (ost[0]-1)) / 2;
    cout << cnt;
    return 0;
}
