#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bieo cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
const int MOD = 998244353;

int fat(int x, int k){
    for (int i = 1; i <= k; i++)
    {
        x = (x*i)%MOD;
    }
    return x%MOD;
}

signed main() {
    bieo;

    int t;
    cin >> t;

    while(t--){
        string s;
        cin >> s;

        int ans = 1;
        int k = s.size(), n = s.size();

        int l = 0;
        while (l < n)
        {
            int r = l+1;
            while(r < n && s[l] == s[r]) r++;
            ans = (ans*(r-l))%MOD;
            k--;
            l = r;
        }

        ans = fat(ans, k)%MOD;
        
        cout << k << " " << ans << endl;
    }
        
    return 0;
}
