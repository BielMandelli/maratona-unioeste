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

        vector<int> a(n), b;
        int m = 1e9;
        for(auto &x : a) {
            cin >> x;
            b.push_back(x);
            m = min(m, x);
        }

        sort(b.begin(), b.end());
        
        bool valid = true;
        for (int i = 0; i < n; i++) if(a[i] != b[i] && a[i]%m) valid = false;
        
        if(valid) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
        
    return 0;
}
