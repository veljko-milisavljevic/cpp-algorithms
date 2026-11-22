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
        int n;
        cin >> n;
        int maks = 0;
        do
        {
            maks = max(maks, n % 10);
            n /= 10;
        }while(n > 0);
        cout << maks << '\n';
        t--;
    }while(t > 0);
    return 0;
}
