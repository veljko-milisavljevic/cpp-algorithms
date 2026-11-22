#include <bits/stdc++.h>

using namespace std;

int KMP(string uzorak, string text)
{
    int tabela[uzorak.size()] = {0};
    int i = 0;
    int j = 1;
    //Popunjavanje LPS tabele
    while(j < uzorak.size())
    {
        if(uzorak[i] == uzorak[j])
        {
            tabela[j] = i+1;
            i++;
            j++;
        }
        else if(i == 0)
        {
            j++;
        }
        else
        {
            i = tabela[i-1];
        }

    }
    //Pretraga
    i = 0;
    j = 0;
    while(j < uzorak.size() && i <= text.size())
    {
        if(text[i] == uzorak[j])
        {
            i++;
            j++;
        }
        else if(j != 0)
        {
            j = tabela[j-1];
        }
        else
        {
            i++;
        }
    }
    /*cout << "i: " << i << " j: " << j << '\n';
    cout << "Text: " << text << '\n';
    cout << "Uzorak: " << uzorak << '\n';
    cout << "text.size() = " << text.size() << '\n';*/
    if(i <= text.size()) return i-j;
    else return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string T;
    cin >> T;

    int l = 0;
    int r = T.size()-1;
    while(l < r)
    {
        if(T[l] == T[r])
        {
            l++;
            r--;
        }
        else
        {
            break;
        }
    }
    if(l >= r)
    {
        cout << 1; //T je palindrom
    }
    else
    {
        string tekst = T.substr(l, r-l+1);
        int d1 = 0;
        int d2 = 0;
        string uzorak = "";
        //Pretraga sa leva na desno
        for(int i = l; i < r; i++)
        {
            uzorak += T[i];
            if(KMP(uzorak, tekst.substr(i-l+1, r-i+1)) != -1)
            {
                d1++;
            }
            else break;
        }

        //Pretraga sa desna na levo
        tekst = T.substr(l, r-l+1);
        uzorak = "";
        for(int i = r; i > l; i--)
        {
            uzorak += T[i];
            if(KMP(uzorak, tekst.substr(l, i-l-1)) != -1)
            {
                d2++;
            }
            else break;
        }

        cout << T.size() - 2*l - max(d1,d2);
    }
    return 0;
}
