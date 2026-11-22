#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    int T[N];
    int X[N];
    for(int i = 0; i < N; i++)
    {
        cin >> T[i] >> X[i];
    }
    int maksimum = 0;
    int minimum = INT_MAX;
    int trenutno = 0;
    for(int i = 0; i < N; i++)
    {
        if(T[i] == 0) trenutno += X[i];
        else trenutno -= X[i];
        maksimum = max(maksimum, trenutno);
        minimum = min(minimum, trenutno);
    }
    cout << maksimum + abs(minimum);
    return 0;
}
