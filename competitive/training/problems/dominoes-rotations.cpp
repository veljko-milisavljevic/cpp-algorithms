#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    int L[N];
    int R[N];
    for(int i = 0; i < N; i++)
    {
        cin >> L[i] >> R[i];
    }
    int cnt = 0;
    int temp;
    if(R[0] != L[1] && (L[0] == L[1] || L[0] == R[1]))
    {
        cnt++;
        //Zamena
        temp = L[0];
        L[0] = R[0];
        R[0] = temp;
    }
    for(int i = 1; i < N; i++)
    {
        if(R[i-1] != L[i] && R[i-1] == R[i])
        {
            cnt++;
            //Zamena
            temp = L[i];
            L[i] = R[i];
            R[i] = temp;
        }
        else if(R[i-1] != L[i] && R[i-1] != R[i])
        {
            cout << -1;
            return 0;
        }
    }
    cout << cnt;
    return 0;
}
