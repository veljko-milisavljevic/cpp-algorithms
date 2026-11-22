#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int cnt = n;
    long long br1[33] = {0};
    while(cnt--)
    {
        int a;
        cin >> a;
        for(int i = 0; a > 0; i++)
        {
            if(a % 2 != 0) br1[i]++;

            a /= 2;
        }
    }
    long long suma = 0;
    for(int i = 0; i <= 32; i++)
    {
        suma += br1[i]*((long long)n-br1[i]);
    }
    cout << suma;
    return 0;
}
