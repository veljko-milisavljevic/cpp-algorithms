#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    int A[N];
    int X[1001] = {0};
    int maks = 0;
    int zbir = 0;
    for(int i = 0; i < N; i++)
    {
        cin >> A[i];
        zbir += A[i];
        X[A[i]] += A[i];
        maks = max(maks, X[A[i]]);
    }
    cout << zbir - maks;
    return 0;
}
