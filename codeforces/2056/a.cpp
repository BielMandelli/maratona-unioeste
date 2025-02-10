#include <bits/stdc++.h>
#define int long long
using namespace std;
#define MOD = 1e9 + 7;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n, m;
        cin >> n >> m;

        vector<pair<int,int>> c(n);

        for (auto &x : c) cin >> x.first >> x.second;

        int initialI = 0, initialJ = 0, pos = 0;
        while(n--){

            initialJ += c[pos].first;
            initialI += c[pos].second;

            pos++;
        }

        int ans = 0, jf = initialJ + m - c[0].second, im = initialI + m - c[0].first;

        ans = jf*2 + im*2;

        cout << ans << endl;
    }

    return 0;
}