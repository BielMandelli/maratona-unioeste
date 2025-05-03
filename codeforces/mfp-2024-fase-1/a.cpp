#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bieo cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

signed main() {
    bieo;
    int n, p, mi;
    cin >> n >> p;

    vector<int> a(n);
    for(auto &x : a) {
        cin >> x;
        mi = min(mi, x);
    }

    int l = 0, r = mi*p, mid, ans;
    while (l <= r)
    {
        mid = (r + l)/2;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += mid/a[i];
            if(sum >= p) break;
        }
        
        if(sum >= p) {
            ans = mid;
            r = mid-1;
        } else l = mid+1;
    }

    cout << ans << endl;
        
    return 0;
}
