#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    int niz[N+1];
    for(int i = 2; i <= N; i++)
    {
        cin >> niz[i];
    }

    pair<int, int> karte[M];
    for(int i = 0; i < M; i++)
    {
        cin >> karte[i].first >> karte[i].second;
    }
    sort(karte, karte + M);

    int trenKarata[N+1] = {0};
    int bacenih = 0;

    trenKarata[karte[0].second]++;

    for(int i = 1; i < M; i++)
    {
        if(karte[i].first != karte[i-1].first)
        {

            //Prosledi karte
            for(int j = 1; j <= N; j++)
            {
                if(trenKarata[j] % 2 == 0 && trenKarata[j] != 0)
                {
                    trenKarata[niz[j]] += 0;
                    bacenih += trenKarata[j];
                }
                else if(trenKarata[j] != 0)
                {
                    trenKarata[niz[j]] += 1;
                    bacenih += trenKarata[j] - 1;
                }
                trenKarata[j] = 0;
                //cout << "!";
            }
        }
        trenKarata[karte[i].second]++;

        /*cout << "\nTrenutno stanje: ";
        for(int j = 1; j <= N; j++)
        {
            cout << trenKarata[j] << " ";
        }*/
    }

    //Nastavak bez dodavanja novih karata
    int brojac = N;
    while(brojac--)
    {
        //Prosledi karte
        for(int j = 1; j <= N; j++)
        {
            if(trenKarata[j] % 2 == 0 && trenKarata[j] != 0)
            {
                trenKarata[niz[j]] += 0;
                bacenih += trenKarata[j];
            }
            else if(trenKarata[j] != 0)
            {
                trenKarata[niz[j]] += 1;
                bacenih += trenKarata[j] - 1;
            }
            trenKarata[j] = 0;
            //cout << "!";
        }
    }

    cout << bacenih;
    return 0;
}
