#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    pair<double, double> parovi[N];
    for(int i = 0; i < N; i++)
    {
        cin >> parovi[i].first >> parovi[i].second;
    }
    long long brojac = 0;
    double pr1, pr2;
    for(int i = 0; i < N-1; i++)
    {
        pr1 = (parovi[i].first + parovi[i].second) / 2;
        for(int j = i+1; j < N; j++)
        {
            pr2 = (parovi[j].first + parovi[j].second) / 2;
            if(pr2 >= parovi[i].first && pr2 <= parovi[i].second && pr1 >= parovi[j].first && pr1 <= parovi[j].second)
            {
                brojac++;
            }
        }
    }

    cout << brojac;
    return 0;
}
