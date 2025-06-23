#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

void solve() {
    int a,x,y;
    cin >> a >> x >> y;
    
    if((x <= a && y >= a) or (x >= a && y <= a)) cout << "NO" << endl;
    else cout << "YES" << endl;
}

signed main() {
    bieo;
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}