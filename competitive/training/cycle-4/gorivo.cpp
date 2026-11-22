#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, P;
    cin >> N >> P;

    pair<int, int> par[N+1]; //first -> cena; second -> kolicina goriva
    int suma = 0;
    int brojac = 0;

    //Unos planeta
    for(int i = 1; i <= N; i++)
    {
        cin >> par[i].second >> par[i].first;
    }

    //Posecujemo planetu P
    suma += par[P].second;
    brojac++;
    par[P].second = -1;

    //Sortiranje po ceni
    sort(par, par + N + 1);

    //Prolazak kroz parove
    for(int i = 1; i <= N; i++)
    {
        if(par[i].second - par[i].first >= 0 && par[i].first <= suma)
        {
            suma += par[i].second - par[i].first;
            brojac++;
        }
    }

    //Izlaz
    cout << suma << '\n' << brojac;

    return 0;
}
