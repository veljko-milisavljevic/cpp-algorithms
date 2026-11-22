#include <iostream>
using namespace std;

int niz[200010];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int N;
        cin >> N;

        int pomocni;
        for(int i = 1; i <= N; i++)
        {
            cin >> pomocni;
            niz[pomocni] = i;
        }

        int indMax = niz[1];
        int indMin = niz[1];
        string izlaz = "1";
        for(int i = 2; i <= N; i++)
        {
            indMin = min(indMin, niz[i]);
            indMax = max(indMax, niz[i]);
            if(indMax - indMin == i-1) izlaz += "1";
            else izlaz += "0";
        }
        cout << izlaz << '\n';
    }
    return 0;
}
