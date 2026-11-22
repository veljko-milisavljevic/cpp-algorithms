#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string S;
    cin >> S;

    int brojcano[S.length()+1];
    string P;
    cin >> P;

    for(int i = 0; i < S.length(); i++)
    {
        brojcano[i] = S[i] - 97; //a = 97, b = 98...
        S[i] = P[brojcano[i]];
    }
    cout << S;
    return 0;
}
