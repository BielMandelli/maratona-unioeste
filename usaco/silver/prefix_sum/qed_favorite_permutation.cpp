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
        int n, q;
        cin >> n >> q;
        vector<int> p(n), diff(n);
        for(auto &x : p) cin >> x;

        string s;
        cin >> s;

        for (int i = 1; i <= n; i++) diff[i-1] = p[i-1]-i;
        for (int i = 0; i < n; i++) cout << diff[i] << endl;
        
        int l = 0, r = 0;
        for (int i = 0; i < s.size(); i++) {
            l += -(s[i] == 'L');
            r += (s[i] == 'R');
        }
        
        while (q--)
        {
            int x;
            cin >> x;

            s[x-1] = (s[x-1] == 'L') ? 'R' : 'L'; 
        }
        
        
    }
    
    
    return 0;
}
