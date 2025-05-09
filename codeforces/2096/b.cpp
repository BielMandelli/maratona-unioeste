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
        int n, k;
        cin >> n >> k;
        vector<int> l(n), r(n), minn(n);
        for(auto &x : l) cin >> x;
        for(auto &x : r) cin >> x;

        int ans = 1;
        for (int i = 0; i < n; i++)
        {
            ans += max(l[i], r[i]);
            minn[i] = min(l[i], r[i]);
        }
        
        sort(minn.begin(), minn.end(), greater<>());
        for (int i = 0; i < k-1; i++) ans += minn[i];
        
        cout << ans << endl;
    }
    
    return 0;
}
