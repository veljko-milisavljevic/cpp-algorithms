#include <bits/stdc++.h>

using namespace std;

#define INF 2000000000

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    int niz[N+1];
    int minVrednost[N+1] = {0};
    for(int i = 1; i <= N; i++)
    {
        cin >> niz[i];
        string s = to_string(niz[i]);
        minVrednost[i] = INF;
        int brCifara = s.length();
        for(int j = brCifara; j >= 0; j--)
        {
            //Provera
            if(minVrednost[i] > niz[i] && niz[i] >= minVrednost[i-1])
            {
                minVrednost[i] = niz[i];
            }

            int pom = s[0] - 48;
            char prvi = s[0];
            s.erase(0,1);
            s += prvi;
            niz[i] = stoi(s);
        }
    }

    if(minVrednost[N] == INF)
    {
        cout << "NE";
    }
    else
    {
        cout << "DA";
    }


    return 0;
}
