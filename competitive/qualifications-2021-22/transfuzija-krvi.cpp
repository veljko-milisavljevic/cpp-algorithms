#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    int zalihe[4]; //O A B AB
    cin >> zalihe[0] >> zalihe[1] >> zalihe[2] >> zalihe[3];
    int izlaz [N][4] = {0};
    pair <string, int> pacijenti[N];
    int potraznja[4] = {0}; //O A B AB
    for(int i = 0; i < N; i++)
    {
        cin >> pacijenti[i].first >> pacijenti[i].second;
        if(pacijenti[i].first == "O") potraznja[0] += pacijenti[i].second;
        else if(pacijenti[i].first == "A") potraznja[1] += pacijenti[i].second;
        else if(pacijenti[i].first == "B") potraznja[2] += pacijenti[i].second;
        else potraznja[3] += pacijenti[i].second;
    }
    for(int i = 0; i < N; i++)
    {
        if(pacijenti[i].first == "O")
        {
            zalihe[0] -= pacijenti[i].second;
            izlaz[i][0] = pacijenti[i].second;
        }
        else if(pacijenti[i].first == "A")
        {
            if(zalihe[1] >= pacijenti[i].second)
            {
                zalihe[1] -= pacijenti[i].second;
                izlaz[i][1] = pacijenti[i].second;
            }
            else
            {
                //Dati svu dostupnu A
                pacijenti[i].second -= zalihe[1];
                izlaz[i][1] = zalihe[1];
                zalihe[1] = 0;
                //Preostalo popuniti sa O
                zalihe[0] -= pacijenti[i].second;
                izlaz[i][0] = pacijenti[i].second;
            }
        }
        else if(pacijenti[i].first == "B")
        {
            if(zalihe[2] >= pacijenti[i].second)
            {
                zalihe[2] -= pacijenti[i].second;
                izlaz[i][2] = pacijenti[i].second;
            }
            else
            {
                //Dati svu dostupnu B
                pacijenti[i].second -= zalihe[2];
                izlaz[i][2] = zalihe[2];
                zalihe[2] = 0;
                //Preostalo popuniti sa O
                zalihe[0] -= pacijenti[i].second;
                izlaz[i][0] = pacijenti[i].second;
            }
        }
        else if(pacijenti[i].first == "AB")
        {
            if(zalihe[3] >= pacijenti[i].second)
            {
                zalihe[3] -= pacijenti[i].second;
                izlaz[i][3] = pacijenti[i].second;
            }
            else
            {
                //Dati svu dostupnu AB
                pacijenti[i].second -= zalihe[3];
                izlaz[i][3] = zalihe[3];
                zalihe[3] = 0;

                //Popuniti ostalo sa A ili B (onom koja ima najvecu razliku zaliha i potraznje)
                if(zalihe[1] - potraznja[1] >= zalihe[2] - potraznja[2])
                {
                    zalihe[1] -= min(pacijenti[i].second, max(zalihe[1] - potraznja[1], 0));
                    izlaz[i][1] = min(pacijenti[i].second, max(zalihe[1] - potraznja[1], 0));
                    pacijenti[i].second -= izlaz[i][1];

                    zalihe[2] -= min(pacijenti[i].second, max(zalihe[2] - potraznja[2], 0));
                    izlaz[i][2] = min(pacijenti[i].second, max(zalihe[2] - potraznja[2], 0));
                    pacijenti[i].second -= izlaz[i][2];
                }
                else
                {
                    zalihe[2] -= min(pacijenti[i].second, max(zalihe[2] - potraznja[2], 0));
                    izlaz[i][2] = min(pacijenti[i].second, max(zalihe[2] - potraznja[2], 0));
                    pacijenti[i].second -= izlaz[i][2];

                    zalihe[1] -= min(pacijenti[i].second, max(zalihe[1] - potraznja[1], 0));
                    izlaz[i][1] = min(pacijenti[i].second, max(zalihe[1] - potraznja[1], 0));
                    pacijenti[i].second -= izlaz[i][1];
                }


                //Preostalo popuniti sa O
                zalihe[0] -= pacijenti[i].second;
                izlaz[i][0] = pacijenti[i].second;
            }
        }
    }
    //Ispis rezultata
    if(zalihe[0] < 0)
    {
        cout << "nemoguce";
    }
    else
    {
        cout << "moguce\n";
        for(int i = 0; i < N; i++)
        {
            cout << izlaz[i][0] << " " << izlaz[i][1] << " " << izlaz[i][2] << " " << izlaz[i][3] << '\n';
        }
    }

    return 0;
}
