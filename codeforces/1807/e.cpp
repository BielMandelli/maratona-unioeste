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

        vector<int> a(n+1), psum(n+1);
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            psum[i] = psum[i-1] + a[i];
        } 

        int l = 1, r = n, ans = 0;
        while(l <= r){
            int m = (l+r)/2;
            cout << "? " << (m-l+1) << " ";
            for(int i = l; i <= m; i++) cout << i << " ";
            cout << endl;
            cout.flush();

            int x = 0;
            cin >> x;

            if(x == psum[m]-psum[l-1]){
                l = m+1;
            } else {
                r = m-1;
                ans = m;
            }
        }

        cout << "! " << ans << endl;
        cout.flush();
    }
        
    return 0;
}
