#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    int A[N];
    int parnih = 0;
    int neparnih = 0;
    for(int i = 0; i < N; i++)
    {
        cin >> A[i];
        if(A[i] % 2 == 0) parnih++;
        else neparnih++;
    }
    cout << parnih*neparnih;
    return 0;
}
