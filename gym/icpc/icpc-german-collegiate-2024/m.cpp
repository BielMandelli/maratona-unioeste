#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bieo cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

signed main() {
    bieo;

    int n;

    cin >> n;

    vector<int> p(n), nw(n);
    for(auto &x : p) cin >> x;

    int ans = 0;
    nw[0] = 0;
    for (int i = 1; i < n; i++) nw[i] = p[i] - i;
    
    sort(nw.begin(), nw.end());

    int med;
    if(n%2) med = nw[n/2];
    else med = (nw[n/2] + nw[n/2-1])/2;
    
    for (int i = 0; i < n; i++) ans += abs(nw[i] - med);
    
    cout << ans << endl;
        
    return 0;
}
