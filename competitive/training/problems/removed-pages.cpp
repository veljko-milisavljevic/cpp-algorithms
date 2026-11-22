#include <iostream>

#define MAXN 100010
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    bool strane[MAXN] = {false};
    int a;
    for(int i = 0; i < N; i++)
    {
        cin >> a;
        strane[a] = true;
    }
    int zbir = 0;
    for(int i = 1; i < MAXN - 1; i += 2)
    {
        if(strane[i] || strane[i+1]) zbir++;
    }
    cout << zbir;
    return 0;
}
