#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;

    pair<int,int> niz[n];

    for(int i = 0; i < n; i++)
    {
        cin >> niz[i].first;
        niz[i].second = i;
    }
    sort(niz, niz+n, greater<pair<int,int>>());
    //Suma i indeksi
    long long suma = 0;
    int indeksi[k*m];
    for(int i = 0; i < k*m; i++)
    {
        suma += (long long)niz[i].first;
        indeksi[i] = niz[i].second;
    }
    cout << suma << '\n';
    sort(indeksi, indeksi+(k*m));

    //Podela
    for(int i = 1; i <= k-1; i++)
    {
        cout << indeksi[i*m] << " ";
    }



    return 0;
}
