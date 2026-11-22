#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    do
    {
        int P;
        cin >> P;
        cout << 2 << ' ' << P-1 << '\n';
        t--;
    }while(t > 0);
    return 0;
}
