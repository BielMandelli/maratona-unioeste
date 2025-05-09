#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bieo cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

signed main() {
    bieo;
    int n, q;
    cin >> n >> q;
    vector<int> a(n), diffq(n+2);
    vector<pair<int,int>> qi(q); 
    for(auto &x : a) cin >> x;
    for(auto &x : qi) cin >> x.first >> x.second;

    sort(a.begin(), a.end(), greater<int>());

    map<int, int> cnt;
    for (int i = 0; i < q; i++)
    {
        diffq[qi[i].first]++;
        diffq[qi[i].second+1]--;
    }

    int cur = 0;
    for (int i = 1; i < n+1; i++)
    {
        cur += diffq[i];
        cnt[i] = cur;
    }
    
    vector<pair<int, int>> cntv(cnt.begin(), cnt.end());
    sort(cntv.begin(), cntv.end(), [](auto &a, auto &b) {
        return a.second > b.second;  
    });

    vector<int> ra(n+1), psum(n+1);

    int i = 0;
    for (auto [f,s] : cntv)
    {
        ra[f] = a[i];
        i++;
    }
    
    for (int i = 1; i <= n; i++) psum[i] = psum[i-1] + ra[i];
    
    int ans = 0;
    for (int i = 0; i < q; i++) ans += psum[qi[i].second] - psum[qi[i].first-1];
    
    cout << ans << endl;

    return 0;
}
