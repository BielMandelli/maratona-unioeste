#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bieo cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

signed main() {
    bieo;
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for(auto &m : a) cin >> m;
    map<int, int> psum;

    int ans = 0, sum = 0;
    psum[0] = 1;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        ans += psum[sum - x];
        psum[sum]++;
    }
    
    cout << ans << endl;
    
    return 0;
}
