#include <bits/stdc++.h>

using namespace std;

int BinarnaPretraga(int A[], int t, int l, int r) // niz, trazeni, pocetak, kraj
{
    if(r >= l)
    {
        int sredina = l + (r - l) / 2;

        if(A[sredina] == t)
        {
            return sredina;
        }

        if(A[sredina] > t)
        {
            return BinarnaPretraga(A, t, l, sredina - 1);
        }

        return BinarnaPretraga(A, t, sredina + 1, r);
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int niz[n];
    for(int i = 0; i < n; i++)
    {
        cin >> niz[i];
    }
    sort(niz, niz + n);
    long long zbir = 0;
    long long mod = 1000000007;
    long long stepeni_dvojke[n+1] = {0};
    stepeni_dvojke[0] = 1;

    for(int i = 0; i < n; i++) stepeni_dvojke[i+1] = (stepeni_dvojke[i]*2) % mod;

    for(int i = 0; i < n; i++)
    {

        if(2*niz[i] == m) zbir++;
        else
        {
            int bp = BinarnaPretraga(niz, m - niz[i], i+1, n-1);
            if(bp < 0) continue;
            else
            {
                int razlika = bp - i - 1;
                zbir = (zbir + stepeni_dvojke[razlika]) % mod;
            }
        }

    }
    cout << zbir;
    return 0;
}
