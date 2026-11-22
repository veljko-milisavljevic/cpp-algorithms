#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, K;
    cin >> N >> K;
    int niz[N];
    vector<int> preci;
    for(int i = 0; i < N; i++)
    {
        cin >> niz[i];
        bool postoji = false;
        int provera = niz[i] / K;
        for(auto it : preci)
        {
            if(it == provera)
            {
                postoji = true;
            }
        }
        if(!postoji) preci.push_back(provera);
    }
    cout << preci.size();
    return 0;
}
