#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    do
    {
        int W, H, x1, x2, y1, y2;
        cin >> W >> H >> x1 >> y1 >> x2 >> y2;
        int w, h;
        cin >> w >> h;
        //4 moguće pozicije; 4 ćoška sobe
        int horizontalnoL, horizontalnoD, vertikalnoG, vertikalnoD;
        horizontalnoL = max(x2-(W-w), 0); if(x1 - horizontalnoL < 0) horizontalnoL = INT_MAX;
        horizontalnoD = max(w-x1, 0); if(x2 + horizontalnoD > W) horizontalnoD = INT_MAX;
        vertikalnoG = max(h-y1,0); if(y2 + vertikalnoG > H) vertikalnoG = INT_MAX;
        vertikalnoD = max(y2-(H-h), 0); if(y1 - vertikalnoD < 0) vertikalnoD = INT_MAX;

        int pomeranje = min(min(horizontalnoD, horizontalnoL), min(vertikalnoD, vertikalnoG));

        if(pomeranje == INT_MAX) cout << -1 << '\n';
        else cout << pomeranje << '\n';
        t--;
    }while(t > 0);
    return 0;
}
