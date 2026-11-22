#include <bits/stdc++.h>

using namespace std;

bool jednaki(int zbirRed[], int zbirKol[],int N)
{
    for(int i = 1; i < N; i++)
    {
        if(zbirRed[0] != zbirRed[i] || zbirKol[0] != zbirKol[i]) return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    int zbirRed[N] = {0};
    int zbirKol[N] = {0};
    int A[N][N];
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> A[i][j];
            zbirRed[i] += A[i][j];
            zbirKol[j] += A[i][j];
        }
    }

    //Racunanje maksimuma
    int maksimum = 0;
    for(int i = 0; i < N; i++)
    {
        maksimum = max(maksimum, zbirKol[i]);
        maksimum = max(maksimum, zbirRed[i]);
    }


    while(!jednaki(zbirRed, zbirKol, N))
    {
        int minR = zbirRed[0];
        int minK = zbirKol[0];
        int indR = 0;
        int indK = 0;
        for(int i = 1; i < N; i++)
        {
            if(minR > zbirRed[i])
            {
                minR = zbirRed[i];
                indR = i;
            }
            if(minK > zbirKol[i])
            {
                minK = zbirKol[i];
                indK = i;
            }
        }
        int vrednost = maksimum - max(zbirRed[indR], zbirKol[indK]);
        A[indR][indK] += vrednost;
        zbirRed[indR] += vrednost;
        zbirKol[indK] += vrednost;
    }
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cout << A[i][j] << " ";
        }
    }
    return 0;
}
