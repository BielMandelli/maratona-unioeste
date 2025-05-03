#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bieo cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

signed main() {
    bieo;

    int n, p , k;
    cin >> n >> p >> k;

    int ans = (p - 1 + k) % (n-1) + 1;
    if(ans >= p) ans++;
    
    cout << ans << endl;
    return 0;
}
