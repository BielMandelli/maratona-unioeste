#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bieo cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

signed main() {
    bieo;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) { cin >> a[i]; }
        
        vector<int> psum(n), ssum(n);
        for (int i = 0; i < n; i++)
        {
            psum[i] = a[i] + i;
            ssum[i] = a[i] - i;
        }

        for (int i = 1; i < n; i++) psum[i] = max(psum[i], psum[i-1]);
        for (int i = n-2; i >= 0; i--) ssum[i] = max(ssum[i], ssum[i+1]);
        
        int ans = 0;
        for (int i = 1; i < n - 1 ; i++) ans = max(ans, psum[i-1] + a[i] + ssum[i+1]); 

        cout << ans << endl;
    }
    
    
    return 0;
}
