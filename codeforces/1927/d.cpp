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
        int n,q;
        cin >> n;
        vector<int> a(n), p(n+1);
        for(auto &x : a) cin >> x;

        p[0] = -1;    
        for (int i = 1; i <= n; i++)
        {
            p[i] = p[i-1];
            if(a[i] != a[i-1]) p[i] = i-1;
        }

        cin >> q;

        while (q--)
        {
            int l, r;
            cin >> l >> r;
            l--; r--;

            if(p[r] < l) cout << -1 << " " << -1 << endl;
            else cout << p[r]+1 << " " << r+1 << endl;
        }
        
        cout << endl;
    }
    
    return 0;
}
