#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long

signed main()
{
    bieo;
    int t;
    cin >> t;

    while (t--)
    {
        int n,k;
        cin >> n >> k;
        vector<int> q1(n), q2(n);
        for(auto &x : q1) cin >> x;
        for(auto &x : q2) cin >> x;

        int ans = 0, sum = 0, mx = 0;
        for (int i = 0; i < min(n,k); ++i) {
            sum += q1[i];
            mx = max(mx, q2[i]);
            ans = max(sum + mx * (k-i-1), ans);
        }

        cout << ans << endl;
    }
    
    return 0;
}