#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long double A, S, K, X, Y;
    cin >> A >> S >> K >> X >> Y;
    cout.precision(9);
    long double izlaz = (long double) (S+K*Y-A)/(X+Y);
    long double temp;
    if(modf(izlaz, &temp) == 0) cout << izlaz;
    else cout << -1;
    return 0;
}
