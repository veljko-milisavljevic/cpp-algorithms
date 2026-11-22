#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    int niz[N];
    static int brPoj[1000010] = {0};

    for(int i = 0; i < N; i++)
    {
        cin >> niz[i];
        brPoj[niz[i]]++;
    }

    sort(niz, niz+N);


    int minimum = N;
    for(int i = 0; i < N; i += brPoj[niz[i]])
    {
        /*cout << "-------------------\n";
        cout << "Trenutni: " << niz[i] << "\n";
        cout << "Manjih od tren: " << i << "\n";
        cout << "Vecih od tren: " << N-(brPoj[niz[i]] + i) << "\n";
        cout << "Br ponavljanja tren: " << brPoj[niz[i]] << "\n";*/
        minimum = min(minimum, max(i, N-(brPoj[niz[i]] + i)));
    }

    cout << minimum;

    return 0;
}
