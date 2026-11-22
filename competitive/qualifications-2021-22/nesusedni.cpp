#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    char c1, c2;
    cin >> c1 >> c2;
    int a1, a2;
    cin >> a1 >> a2;
    if(max(a1, a2) > min(a1, a2) + 1)
    {
        cout << "nemoguce";
    }
    else
    {
        string izlaz;
        if(a1 == a2)
        {
            while(a1--)
            {
                izlaz += c1;
                izlaz += c2;
            }
        }
        else if(a1 > a2)
        {
            while(a2--)
            {
                izlaz += c1;
                izlaz += c2;
            }
            izlaz += c1;
        }
        else
        {
            izlaz += c2;
            while(a1--)
            {
                izlaz += c1;
                izlaz += c2;
            }
        }
        cout << izlaz;
    }

    return 0;
}
