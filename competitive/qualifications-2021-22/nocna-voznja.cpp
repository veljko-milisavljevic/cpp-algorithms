#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    int p[N+1];
    for(int i = 1; i <= N; i++)
    {
        cin >> p[i];
    }
    int povezanosti[N+1][N+1];
    int cnt = N - 1;
    while(cnt > 0)
    {
        int prvi, drugi;
        cin >> prvi >> drugi;
        povezanosti[prvi][drugi] = 1;
        povezanosti[drugi][prvi] = 1;
        cnt--;
    }
    //Inicijalizacija grafa udaljenosti i poseceni
    int udaljenosti[N+1][N+1];
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            if(i == j)
            {
                udaljenosti[i][j] = 0;
            }
            else
            {
                udaljenosti[i][j] = N+1;
            }
        }
    }

    int Q;
    cin >> Q;
    while(Q--)
    {
        int operacija;
        cin >> operacija;
        if(operacija == 1)
        {
            int a, b;
            cin >> a >> b;
            int pomocni;
            pomocni = p[a];
            p[a] = p[b];
            p[b] = pomocni;
        }
        else
        {
            int l, r, x;
            cin >> l >> r >> x;
            int maksimum = 0;
            for(int i = l; i <= r; i++)
            {
                if(udaljenosti[x][p[i]] > N)
                {
                    int poseceni[N+1] = {0};
                    poseceni[x] = 1;
                    int neposecenih = N;
                    int minimum;
                    int indeksMin = x;
                    int u;
                    while(neposecenih > 0)
                    {
                        u = indeksMin;
                        minimum = INT_MAX;
                        poseceni[u] = 1;
                        neposecenih--;
                        for(int j = 1; j <= N; j++)
                        {
                            if(poseceni[j] == 0 && povezanosti[u][j] != 0 && udaljenosti[x][j] > (udaljenosti[x][u]+povezanosti[u][j]))
                            {
                                udaljenosti[x][j] = (udaljenosti[x][u]+povezanosti[u][j]);
                            }
                            if(poseceni[j] == 0 && udaljenosti[x][j] < minimum)//Odabir sledeceg sa kojim radimo
                            {
                                minimum = udaljenosti[x][j];
                                indeksMin = j;
                            }
                        }
                    }
                }
                maksimum = max(maksimum, udaljenosti[x][p[i]]);
            }
            cout << maksimum << '\n';

        }

    }
    return 0;
}
