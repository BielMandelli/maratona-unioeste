#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bieo cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

signed main() {
    bieo;
    int n;
    cin >> n;
    while(n--){
        int x,y;
        cin >> x >> y;

        int ans = 0;
        if((x > 0 && y > 0) or (x < 0 && y < 0)) cout << abs(x) + abs(y) << endl;
        else if(x == 0 && y == 0) cout << ans << endl;
        else {
            ans = max(abs(x), abs(y));
            cout << ans << endl;
        }
        
    }
    return 0;
}