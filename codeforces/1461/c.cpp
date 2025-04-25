#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bieo cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

signed main() {
    bieo;
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> p(n);
        int last = n-1;
        for(auto &x : p) cin >> x;
        
        while(last >= 0 && p[last] == last+1) last--;

        double ans = 1.0;
        if(last == -1) ans = 0.0;

        while (m--)
        {
            double ri, pi;
            cin >> ri >> pi;

            ri = ri-1;

            if(ri >= last) ans *= (1-pi);
        }
        
        cout << setprecision(6) << fixed;
        cout << 1-ans << endl;
    }
        
    return 0;
}
