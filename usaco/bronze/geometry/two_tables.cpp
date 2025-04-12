#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long

signed main()
{
    bieo;
    int t;
    cin >> t;

    while(t--){
        int x1, y1, x2, y2, w, h, W, H;
        cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> w >> h;

        int ans = 1e9;

        if(x2 - x1 + w <= W){
            ans = min(ans, max(0LL, w - x1));
            ans = min(ans, max(0LL, x2 - (W - w)));
        }

        if(y2 - y1 + h <= H){
            ans = min(ans, max(0LL, h - y1));
            ans = min(ans, max(0LL, y2 - (H - h)));
        }

        cout << fixed << setprecision(9);

        if(ans == 1e9) cout << -1 << endl;
        else cout << (double) ans << endl;
    }
    
    return 0;
}