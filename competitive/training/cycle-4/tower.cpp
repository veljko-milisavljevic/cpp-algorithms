#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, H;
    cin >> N >> H;

    int visine[N+1];
    for(int i = 1; i <= N; i++)
    {
        cin >> visine[i];
    }

    int domet[N+1] = {0};

    int maxV = 0;
    int indM;

    int predhodniBrojac = 0;


    int brojac = 0;
    for(int i = 1; i <= N; i++)
    {
        if(visine[i] > maxV)
        {
            brojac = 0;
            maxV = visine[i];
            indM = i;
        }

        if(visine[i] < H)
        {
            brojac++;
        }
    }
    return 0;
}
