#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);


    int N, M;
    cin >> N >> M;
    int red[N];

    for(int i = 0; i < N; i++)
    {
        cin >> red[i];
    }

    sort(red, red + N);


    int visina = red[N-1];
    int brDrveca = 1;
    int nedostaje = M;
    for(int i = N-1; i > 0; i--)
    {
        if(nedostaje >= (red[i] - red[i-1]) * brDrveca)
        {
            nedostaje -= (red[i] - red[i-1]) * brDrveca;
            visina = red[i-1];
            brDrveca++;
        }
        else
        {
            visina -= nedostaje / brDrveca;
            if(nedostaje % brDrveca != 0)
            {
                visina--;
            }
            break;
        }
    }

    cout << visina;

    return 0;
}
