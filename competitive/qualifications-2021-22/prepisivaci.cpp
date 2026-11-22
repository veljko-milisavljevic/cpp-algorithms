#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    map<pair<double, long long>, int> cnt; //map<pair<nagib, duzina>, brojac>

    int N; cin >> N;
    int x[N];
    int y[N];
    for(int i = 0; i < N; i++)
    {
        cin >> x[i] >> y[i];
    }

    for(int i = 0; i < N-1; i++)
    {
        for(int j = i+1; j < N; j++)
        {
            int deltaX = x[i] - x[j];
            int deltaY = y[i] - y[j];
            double n;
            if(deltaX == 0) n = 0;
            else if(deltaY == 0) n = 100000010;
            else n = (double)deltaY/deltaX;
            cnt[{n, (long long)deltaX*deltaX + (long long)deltaY*deltaY}]++;
            //cout << "Nagib " << i << " prema " << j <<": " << n << "\tDuzina: " << (long long)deltaX*deltaX + (long long)deltaY*deltaY << '\n';
        }
    }

    int broj = 0;
    map<pair<double, long long>, int> cnt2(cnt.begin(), cnt.end());
    for(auto x : cnt)
    {
        double nagib = x.first.first;
        long long duzina = x.first.second;
        broj += (cnt[{nagib, duzina}] * cnt2[{nagib, duzina * 4}]);
        //cout << "\n" << "Nagib: " << nagib << "\tDuzina: " << duzina << "\tCount: " << cnt[x.first] << " " << "broj += " << (cnt[{nagib, duzina}] * cnt2[{nagib, duzina * 4}]);
    }
    cout << broj;
    return 0;
}
