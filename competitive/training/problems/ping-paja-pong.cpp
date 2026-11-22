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
        int x,y,k;
        cin >> x >> y >> k;
        if(((x+y)/k) % 2 == 0) cout << "Chef\n";
        else cout << "Paja\n";
        t--;
    }while(t > 0);
    return 0;
}
