#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, prvi, drugi, treci;
    cin >> N >> prvi >> drugi >> treci;

    int R, G, B;
    if(prvi >= drugi && prvi >= treci)
    {
        R = N - (prvi-1);

        if(drugi >= treci)
        {
            G = (N - R) - (drugi - 1);
            B = N - (R + G);
        }
        else
        {
            B = (N - R) - (treci - 1);
            G = N - (R + B);
        }
    }
    else if(drugi > prvi && drugi >= treci)
    {
        G = N - (drugi-1);

        if(prvi >= treci)
        {
            R = (N - G) - (prvi - 1);
            B = N - (R + G);
        }
        else
        {
            B = (N - G) - (treci - 1);
            R = N - (R + B);
        }
    }
    else
    {
        if(prvi >= drugi)
        {
            R = (N - B) - (prvi - 1);
            G = N - (R + B);
        }
        else
        {
            G = (N - B) - (drugi - 1);
            R = N - (G + B);
        }
    }

    if(R <= 0 || G <= 0 || B <= 0)
    {
        cout << "nemoguce";
    }
    else
    {
        cout << "moguce\n";
        cout << R << ' ' << G << ' ' << B;
    }


    return 0;
}
