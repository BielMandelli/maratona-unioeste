#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

void solve() {
    vector<int> h(2), d(2), t(2);
    for (int i = 0; i < 2; i++) cin >> h[i] >> d[i] >> t[i];
    
    int n1 = h[1]/d[0], n2 = h[0]/d[1];
    double dn1 = (double) h[1]/ (double) d[0], dn2 = (double) h[0]/ (double) d[1];
    if(dn1 > n1) n1++; 
    if(dn2 > n2) n2++;
    int p1 = n1*t[0], p2 = n2*t[1];

    p1-=t[0];
    p2-=t[1];

    if(p1 == p2) cout << "draw" << endl;
    else if(p1 < p2) cout << "player one" << endl;
    else cout << "player two" << endl;
}

signed main() {
    bieo;
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
