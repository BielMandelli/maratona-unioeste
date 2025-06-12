#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, p, v, hp;
    cin >> a >> p >> v;

    int ans = (2*(v*p - a))/v;

    cout << ans << endl;
    
    return 0;
}
