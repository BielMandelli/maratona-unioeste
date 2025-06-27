#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'
#define ld long double

void solve() {
    ld d, m;
    cin >> d >> m;

    ld r2 = sqrt(2.0L);
    ld diag = d*r2;
    
    int qnt = m/diag;
    ld frac = (m-qnt*diag)/r2;

    ld x,y;
    x = qnt*d+frac;

    if(qnt%2) y = d-frac;
    else y = frac;
    
    cout << setprecision(10) << fixed;
    cout << x << " " << y << endl;
}

signed main() {
    bieo;
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}