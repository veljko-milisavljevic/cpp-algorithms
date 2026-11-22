#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    int A[N];
    for(int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    sort(A, A+N);
    int suma = 0;
    for(int i = 1; i < N; i += 2)
    {
        suma += A[i] - A[i-1];
    }
    cout << suma;
    return 0;
}
