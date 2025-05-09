#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bieo cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

signed main() {
    bieo;
    int n, k;
    cin >> n >> k;

    vector<int> d(n);
    for(auto &x : d) cin >> x;

    sort(d.begin(), d.end());

    vector<int> lf(n), rg(n);
    int l = 0, r = 0, ans = 0;
    while (r < n)
    {
        if(d[r] - d[l] <= k){
            r++;
            lf[r-1] = rg[l] = r-l;
        } else l++;
    }

    for (int i = 1; i < n; i++)
    {
        ans = max(ans, rg[i] + lf[i-1]);
        lf[i] = max(lf[i], lf[i-1]);
    }
    
    cout << ans << endl;
    
    return 0;
}
