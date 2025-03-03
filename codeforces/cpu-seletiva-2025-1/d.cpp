#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> p(n*2);
    for(auto &x : p) cin >> x;

    sort(p.begin(), p.end());
    int ans = 0;
    for (int i = 0; i < n*2; i+=2)
    {
        ans += max(p[i], p[i+1]);
    }

    cout << ans << endl;
    
    return 0;
}
