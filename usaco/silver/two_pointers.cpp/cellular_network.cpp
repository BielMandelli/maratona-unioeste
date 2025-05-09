#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long

signed main()
{
    bieo;
    int n, m;
    cin >> n >> m;
    vector<int> cit(n), tow(m);
    for(auto &x : cit) cin >> x;
    for(auto &x : tow) cin >> x;

    int ans = 0;
    for (auto city : cit)
    {
        int dist = 1e14;
        auto it = lower_bound(tow.begin(), tow.end(), city);
        if(it != tow.end()) dist = *it - city;
        if(it != tow.begin()) {
            --it;
            dist = min(dist, city - *it);
        }
        // cout << "it " << *it << " dist" << dist << endl;
        ans = max(ans, dist);
    }
    
    cout << ans << endl;

    return 0;
}