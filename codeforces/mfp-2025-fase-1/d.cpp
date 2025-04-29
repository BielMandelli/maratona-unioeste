#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bieo cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

const double pi = 3.14159265359;

signed main() {
    bieo;
    int n,q;
    vector<int> r(3);
    for(auto &x : r) cin >> x;
    cin >> n >> q;

    cout << setprecision(10) << fixed;
    double theta = (2 * pi) / n;

    while (q--)
    {
        int c1,l1,c2,l2;
        cin >> c1 >> l1 >> c2 >> l2;
        c1--; c2--; 

        double ans = 1e18;

        for (int cur = 0; cur < 3; ++cur) {
            double radial = abs(r[c1] - r[cur]) + abs(r[c2] - r[cur]);
 
            int diff = abs(l1 - l2);
            diff = min(diff, n - diff);
 
            double ang = diff * theta * r[cur];
 
            double total = radial + ang;
            ans = min(ans, total);
        }
    
        if (c1 == c2) {
            int diff = abs(l1 - l2);

            diff = min(diff, n - diff);

            double ang = diff * theta * r[c1];

            ans = min(ans, ang);
        }

        cout << ans << endl;
    }
    
    return 0;
}
