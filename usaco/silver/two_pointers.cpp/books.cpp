#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bieo cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

signed main() {
    bieo;
    int n, t;
    cin >> n >> t;

    vector<int> a(n);
    for(auto &x : a) cin >> x;

    int l = 0, r = 0, ans = 0, cur = 0, time = 0;
    while (r < n)
    {
        if(time+a[r] <= t){
            time += a[r];
            cur++;
            r++;
        } else {
            time -= a[l];
            cur--;
            l++;
        }

        ans = max(ans, cur);
    }
    
    cout << ans << endl;
        
    return 0;
}
