#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string T; cin >> T;
    string S; cin >> S;

    map<char, int> brojSl;
    int pocetak = T.find(S[0]); //prvo pojavljivanje prvog slova zabranjene reci
    int kraj = T.find_last_of(S[S.length()-1]); //poslednje pojavljivanje poslednjeg slova zabranjene reci
    for(int i = pocetak; i <= kraj; i++)
    {
        brojSl[T[i]]++;
    }
    int minimum = INT_MAX;
    int indMin;
    for(int i = 0; i < S.length(); i++)
    {
        if(brojSl[S[i]] < minimum)
        {
            minimum = brojSl[S[i]];
            indMin = i;
        }
    }
    for(int i = 0; i < T.length(); i++)
    {
        if(T[i] == S[indMin])
        {
            T[i] = '*';
        }
    }
    cout << minimum << '\n' << T;
    return 0;
}
