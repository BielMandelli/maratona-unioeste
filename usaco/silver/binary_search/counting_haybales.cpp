#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bieo cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

signed main() {
    bieo;
    int n,q;
    cin >> n >> q;
    vector<int> h(n);
    for(auto &x : h) cin >> x;

    sort(h.begin(), h.end());

    while (q--)
    {
        int l,r;
        cin >> l >> r;
        auto it = lower_bound(h.begin(), h.end(), l);
        auto it2 = upper_bound(h.begin(), h.end(), r);

        int ans = (it2 - h.begin()) - (it - h.begin());

        // cout << "it2> " << (it2 - h.begin()) << " it> " << (it - h.begin()) << endl;
        // cout << "it " << (it2 - h.begin())  (it - h.begin()) << endl;

        cout << ans << endl;
    }
    
    
    return 0;
}
