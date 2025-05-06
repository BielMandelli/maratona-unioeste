#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bieo cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

signed main() {
    bieo;

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<int> a(n);
        for(auto &x : a) cin >> x;

        vector<int> valid;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if(a[i] >= i+1) continue;
            ans += (int) (lower_bound(valid.begin(), valid.end(), a[i]) - valid.begin());
            valid.push_back(i+1);
        }
        
        cout << ans << endl;
    }
        
    return 0;
}
