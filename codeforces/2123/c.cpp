#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x : a) cin >> x;

    vector<int> pmin(n), smax(n);
    pmin[0] = a[0];
    for(int i = 1; i < n; i++) pmin[i] = min(pmin[i-1], a[i]);
    
    smax[n-1] = a[n-1];
    for(int i = n-2; i >= 0; i--) smax[i] = max(smax[i+1], a[i]);
    
    for(int i = 0; i < n; i++) {
        if (a[i] == pmin[i] || a[i] == smax[i]) cout << '1';
        else cout << '0';
    }
    cout << endl;
}


signed main()
{
    bieo;
    int t=1;
    cin >> t;

    while (t--) solve();
    
    return 0;
}