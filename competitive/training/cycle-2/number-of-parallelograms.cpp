#include <bits/stdc++.h>
#define MAXN 1000010

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    int x[N], y[N];

    for(int i = 0; i < N; i++)
    {
        cin >> x[i] >> y[i];
    }

    map<pair<int, int>, int> cnt;
    for(int i = 0; i < N-1; i++)
    {
        for(int j = i+1; j < N; j++)
        {
            cnt[{x[i]+x[j], y[i]+y[j]}]++;
        }
    }

    int c = 0;
    for(auto t:cnt)
    {
        c += (t.second *(t.second - 1))/2;
    }

    cout << c;

    return 0;
}
