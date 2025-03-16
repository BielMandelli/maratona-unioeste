#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
#define int long long
const int MOD = 1e9 + 7;

signed main()
{
    fastio;
    int t;
    cin >> t;
    while(t--){
        int n, h;
        cin >> n >> h;

        vector<int> hit(n);
        for(auto &x : hit) cin >> x;

        int l = 0, r = 1e18, m, sum;
        while (l <= r)
        {
            m = (l + r) / 2;
            sum = m;
            for (int i = 0; i < n-1; i++) sum += min(m, hit[i+1] - hit[i]);
            if(sum < h) l = m + 1;
            else r = m - 1;
        }
        
        cout << r + 1 << endl;
    }

    return 0;
}