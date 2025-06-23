#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

void solve() {
    int a,b,c;
    cin >> a >> b >> c;

    int ans = 0;
    ans += a*2;
    if(c > 1) {
        ans += (b*2+1) + 2;
        c -= 2;
    }
    if(c > 1) {
        ans += c/2*3;
        c -= 2;
    }

    cout << ans << endl;
}

signed main() {
    bieo;
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
