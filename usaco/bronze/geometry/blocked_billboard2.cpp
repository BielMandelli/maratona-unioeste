#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long

struct Rectangle{
    int x1,x2,y1,y2;

    int area() {return (x2-x1) * (y2-y1);}
};

signed main()
{
    bieo;
    Rectangle a,b;
    int bestX, bestY, ans;
    cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
    cin >> b.x1 >> b.y1 >> b.x2 >> b.y2;

    bestX = max(a.x2, b.x2) - min(a.x1, b.x1);
    bestY = max(a.y2, b.y2) - min(a.y1, b.y1);

    ans = max(bestX, bestY);
    cout << ans * ans << endl;
    
    return 0;
}