#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bieo cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
const int MOD = 32768;

signed main() {
    bieo;

    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x : a) cin >> x;
    
    for (int x = 0; x < n; x++){
        int ans = 1e9;

        for (int i = 0; i <= 15; i++)
        {
            for (int j = 0; j <= 15; j++)
            {
                if(((a[x] + i) * (1<<j)) % MOD == 0) ans = min(ans, i + j);
            }
        }

        cout << ans << endl;
    }
    
    
    return 0;
}
