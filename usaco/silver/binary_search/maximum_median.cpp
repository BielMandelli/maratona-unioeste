#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bieo cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

signed main() {
    bieo;
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(auto &x : a) cin >> x;

    sort(a.begin(), a.end());

    int med = a[n/2];

    int l = 0, r = 2e9, ans;
    while(l < r){
        int m = (l+r+1)/2;
        int ksum = 0;
        for (int i = n/2; i < n; i++) ksum += max(0LL, m - a[i]);
        if(ksum <= k) {
            l = m;
            ans = m;
        }
        else r = m-1;
    }

    cout << ans << endl;
    
    return 0;
}
