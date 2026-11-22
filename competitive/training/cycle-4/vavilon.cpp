#include <bits/stdc++.h>

using namespace std;

const int mod = 1000000007;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n, m, id;
    cin >> n >> m >> id;

    long long rezultat = 2; //Pomnozen sa 2

    //Racunanje NZS
    int br = 0;
    for(int i = 2; i*i <= id; i++)
    {
        if(id % i == 0)
        {
            br++;
        }
    }
    br *= 2;
    br++;

    for(int i = 0; i < n-1; i++)
    {

        rezultat = (rezultat * (m/id - 1 - i) * br) % mod; //Dodajemo NZD i NZS
        br--;
    }

    cout << rezultat;

    return 0;
}
