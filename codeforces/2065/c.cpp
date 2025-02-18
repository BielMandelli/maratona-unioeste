#include <bits/stdc++.h>
#define int long long
const int MAXX = 1e17;
using namespace std;

signed main (){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n,m;
        cin >> n >> m;
        vector<int> a(n),b(m);

        for(auto &x: a) cin >> x;
        for(auto &x: b) cin >> x;

        bool isTrue = true;
        int minor, maxi;
        for (int i = 0, j = 0; i < n; i++)
        {
            if(i == 0) {
                a[i] = min(a[i], b[j] - a[i]);
                continue;
            }
            
            minor = min(a[i], b[j] - a[i]);
            if(minor < a[i-1]) {
                maxi = max(a[i], b[j] - a[i]);
                if(maxi < a[i-1]){
                    isTrue = false;
                    break;
                }
                a[i] = maxi;
            }
            else {
                a[i] = minor;
            }
        }

        if(isTrue) cout << "YES" << endl;
        else cout << "NO" << endl;
        
    }

    return 0;
}