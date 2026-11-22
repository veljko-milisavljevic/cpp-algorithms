#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string N;
    cin >> N;
    string izlaz = "";
    string prvi = "0000" + N;
    string drugi = N + "0000";
    int l = prvi.length();
    int pom = 0;

    for(int i = l; i > 0; i--)
    {
        int cifra1 = prvi[i-1] - 48;
        int cifra2 = drugi[i-1] - 48;
        if(cifra1*cifra2 == 1)
        {
            if(pom == 1) izlaz += '1';
            else
            {
                izlaz += '0';
                pom = 1;
            }
        }
        else if(cifra1+cifra2+pom == 2)
        {
            izlaz += '0';
            pom = 1;
        }
        else if(cifra1+cifra2+pom == 1)
        {
            izlaz += '1';
            pom = 0;
        }
        else
        {
            izlaz += '0';
        }
    }
    if(pom == 1) izlaz += '1';
    string invIzlaz = "";
    for(int i = izlaz.size() - 1; i >= 0; i--)
    {
        invIzlaz += izlaz[i];
    }
    cout << invIzlaz;
    return 0;
}
