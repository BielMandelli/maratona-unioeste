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
        int n,m;
        cin >> n >> m;
        vector<int> a(n), b(m);
        for(auto &x : a) cin >> x;
        for(auto &x : b) cin >> x;

        sort(a.begin(), a.end(), greater<int>());

        int ans = 0;
        int i = 0, j = 0;
        while (i<n)
        {
            // cout << "pres " << b[j] << " pessoa " << a[i];
            if(j >= m or b[a[i]-1] < b[j]) {
                ans+= b[a[i]-1];
                i++;
                // cout << " valor " << b[a[i]-1];
            }
            else {
                ans += b[j];
                // cout << " valor " << b[j];
                i++;
                j++;
            }

            cout << endl;
        }
        
        cout << ans << endl;

    }
        
    return 0;
}
