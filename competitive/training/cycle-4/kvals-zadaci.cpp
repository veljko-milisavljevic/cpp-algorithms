#include <bits/stdc++.h>

using namespace std;

const int mod = 1000000007;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    //Unos niza
    int N;
    cin >> N;
    int niz[N];
    for(int i = 0; i < N; i++)
    {
        cin >> niz[i];
    }

    //Sortiranje niza
    sort(niz, niz + N);

    map<int, int> mapa;
    for(int i = 0; i < N; i++)
    {
        //mapa[niz[i]] = rez[i];
    }

    int rez = 0;

    int stepen = 1;

    int l = 0;
    //int r = 0;
    for(int i = 0; i < N; i++)
    {
        if(i + 1 < N)
        {
            if(niz[i] != niz[i+1])
            {
                for(int j = l; l <= i; j++)
                {
                    mapa[niz[j]] = rez;
                }
                l = i+1;
            }
        }
        else
        {
            for(int j = l; l <= i; j++)
            {
                mapa[niz[j]] = rez;
            }
        }



        rez = (rez + stepen) % mod;
        stepen = stepen * 2 % mod;

        //r++;
    }

    /*for(int i = 0; i < N; i++)
    {
        cout << rez[i] << " ";
    }
    cout << '\n';*/



    //Unos primera
    int Q;
    cin >> Q;

    while(Q--)
    {
        int trazeni;
        cin >> trazeni;

        cout << mapa[trazeni] << '\n';
    }

    /*while(Q--)
    {
        int trazeni;
        cin >> trazeni;

        //Pretraga po primeru
        int r = 0;
        int stepen = 1;
        for(int i = 0; i < N; i++)
        {

            if(niz[i] == trazeni)
            {
                r = (r + stepen) % mod;
            }
            else if(niz[i] > trazeni) //Izlaz iz petlje, optimizacija
            {
                break;
            }
            stepen = stepen * 2 % mod;
        }
        cout << r << '\n';
    }*/
    return 0;
}
