#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,t,low = 1e9;
    cin >> n >> t;
    vector<int> k(n);
    for(auto &x : k){
        cin >> x;
        low = min(low, x);
    }

    int l = 0, r = 1e18, ans;
    while(l <= r){
        int m = (l+r)/2;
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += m/k[i];
            if(sum >= t) break;
        }
        if(sum >= t){
            ans = m;
            r = m - 1;
        } else l = m + 1;
    }

    cout << ans << endl;

    return 0;
}