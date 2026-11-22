#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //Unos podataka i popunjavanje 2K + 2 niza
    int K;
    cin >> K;
    long long niz[2*K+2+1] = {0};
    for(int i = 1; i <= K; i++)
    {
        cin >> niz[i];
        niz[i+K+1] = niz[i];

        niz[K+1] ^= niz[i];
        niz[2*K+2] = niz[K+1];
        niz[0] = niz[K+1];
    }

    //Priprema prefiksne sume
    long long pref[2*K+2+1] = {0};
    pref[0] = niz[0];
    for(int i = 1; i <= 2*K+2; i++)
    {
        pref[i] = (pref[i-1] ^ niz[i]);
    }

    int Q;
    cin >> Q;
    while(Q--)
    {
        long long l, r;
        cin >> l >> r;
        l %= (K+1);
        r %= (K+1);

        //if(r < l) r += K+1;
        r += K+1;

        if(l == 0)
        {
            cout << pref[r] << '\n';
        }
        else
        {
            cout << (pref[l-1] ^ pref[r]) << '\n';
        }


    }
    return 0;
}
