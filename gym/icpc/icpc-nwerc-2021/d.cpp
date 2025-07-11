#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

void solve(){
    int n;
    cin >> n;
    vector<pair<int,int>> p(n);
    for(auto &x : p) cin >> x.first >> x.second;

    int r = -1e9, l = -1e9, u = -1e9, d = -1e9;

    bool diag = true;
    pair<int,int> last;
    if(n == 1) diag = false;
    for (int i = 0; i < n; i++)
    {
        if(!i) last = p[i];
        else if(diag) {
            if((abs(p[i].first - last.first) == abs(p[i].second - last.second)) or (abs(p[i].first + last.first) == abs(p[i].second + last.second))) last = p[i];
            else diag = false;
        }
        
        if(r < p[i].first + p[i].second) r = p[i].first + p[i].second;
        if(l < p[i].first - p[i].second) l = p[i].first - p[i].second;
        if(u < -p[i].first + p[i].second) u = -p[i].first + p[i].second;
        if(d < -p[i].first - p[i].second) d = -p[i].first - p[i].second;
    }
    
    cout << (4+r+l+u+d + (diag ? 1 : 0)) << endl;
}

signed main()
{
    bieo;
    int t=1;
    // cin >> t;

    while (t--) solve();
    
    return 0;
}