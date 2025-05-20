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

        vector<int> g(n);
        for(auto &x : g) cin >> x;

        int sum = 0;
        map<int,int> mp;
        mp[0] = 1;

        bool valid = false;
        for (int i = 0; i < n; i++) {
            if(i%2) g[i] = -g[i];
            sum += g[i];
            if(mp[sum]){
                valid = true;
                break;
            }
            mp[sum]++;
        }
        
        if(valid) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    
        
    return 0;
}
