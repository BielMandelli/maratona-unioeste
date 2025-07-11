#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n), psum(n+1, 0);
    for(auto &x : a) cin >> x;

    for (int i = 1; i <= n; i++) psum[i] = psum[i-1] + a[i-1];
    
    while (q--)
    {
        int l,r;
        cin >> l >> r;
        
        cout << psum[r] - psum[l-1] << endl;
    }
    
    
}


signed main()
{
    bieo;
    int t=1;
    // cin >> t;

    while (t--) solve();
    
    return 0;
}