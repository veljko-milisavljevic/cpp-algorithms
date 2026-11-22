#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    int niz[N] = {0};
    int a;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> a;
            niz[i] |= a;
        }
    }

    for(int i = 0; i < N; i++) cout << niz[i] << " ";

    return 0;
}
