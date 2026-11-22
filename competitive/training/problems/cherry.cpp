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
        int a[n] = {0};
        for(int i = 0; i < n; i++) cin >> a[i];
        long long maks = 0;
        for(int i = 0; i < n-1; i++) maks = max(maks, (long long)a[i]*a[i+1]);
        cout << maks << '\n';

        t--;
    }while(t > 0);
    return 0;
}
