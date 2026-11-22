#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    if(N == 1) cout << 1;
    else
    {
        string S[N];
        for(int i = 0; i < N; i++)
        {
            cin >> S[i];
            sort(S[i].begin(), S[i].end());
        }
        sort(S, S+N);
        int maks = 0;
        int trenutno = 1;
        for(int i = 1; i < N; i++)
        {
            if(S[i] == S[i-1])
            {
                trenutno++;
                maks = max(maks, trenutno);
            }
            else
            {
                trenutno = 1;
            }
        }
        cout << maks;
    }
    return 0;
}
