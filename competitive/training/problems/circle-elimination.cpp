#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef struct
{
    int vrednost, index;
}tCvor;

bool Uporedi(tCvor v1, tCvor v2)
{
    if(v1.vrednost < v2.vrednost) return 1;
    else return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<tCvor> cvorovi;
    tCvor cvor;
    for(int i = 0; i < N; i++)
    {
        cin >> cvor.vrednost;
        cvor.index = i;
        cvorovi.push_back(cvor);
    }
    sort(cvorovi.begin(),cvorovi.end(),Uporedi);
    long long zbir = 0;
    for(int i = 0; i < N-1; i++)
    {
        if(cvorovi[i].index < cvorovi[i+1].index)
        {
            zbir += (long long)min((long long)abs(cvorovi[i].index - cvorovi[i+1].index), (long long)cvorovi[i].index + N - cvorovi[i+1].index);
        }
        else
        {
            zbir += (long long)min((long long)abs(cvorovi[i].index - cvorovi[i+1].index), (long long)N - cvorovi[i].index + cvorovi[i+1].index);
        }
    }
    cout << zbir;
    return 0;
}
