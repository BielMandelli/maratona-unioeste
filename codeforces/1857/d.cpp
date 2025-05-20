#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bieo cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

signed main() {
    bieo;
    int t;
    cin>>t;

    while(t--){
        int n;
        cin >> n;

        vector<int> a(n),b(n);
        for(auto &x : a) cin >> x;
        for(auto &x : b) cin >> x;

        int strong = -1e14;
        for (int i = 0; i < n; i++) strong = max(strong, a[i]-b[i]);
        
        int cnt = 0;
        for (int i = 0; i < n; i++) if(strong == a[i]-b[i]) cnt++;

        cout << cnt << endl;
        for (int i = 0; i < n; i++) if(strong == a[i]-b[i]) cout << i+1 << " ";
        cout << endl;
    }
    return 0;
}
