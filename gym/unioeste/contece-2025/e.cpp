#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

void solve() {
    int d, a, n;
    cin >> d >> a >> n;
    int p = n-1;
    if(p >= 15) p = 14;

    int ans = (d + (a*p)) * (31-n+1) ;
    cout << ans << endl;
}


signed main()
{
    bieo;
    int t=1;
    // cin >> t;

    while (t--) solve();
    
    return 0;
}