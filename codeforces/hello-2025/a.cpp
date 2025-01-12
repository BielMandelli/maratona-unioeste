#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main () {
    int t;

    cin >> t;

    while(t--){
        int n, m;
        cin >> n >> m;
        int best = max(n,m);
        int ans = best + 1;
        
        cout << ans << endl;
    }
    return 0;
}