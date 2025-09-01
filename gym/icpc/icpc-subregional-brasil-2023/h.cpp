#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

void solve(){
    int n, s;
    cin >> n >> s;

    vector<tuple<int,int,int>> w;
    for (int i = 1; i <= n; i++)
    {
        int a,b,c;
        cin >> a >> b >> c;

        w.push_back({a, -i, c});
        w.push_back({b, i, c});
    }
    
    sort(w.begin(), w.end());

    set<pair<int,int>> q;
    vector<int> st(n+1);

    int ans = 0;
    for(auto [time, idx, cost] : w){
        if(idx<0){
            idx = abs(idx);
            int best = ans;
            if(q.size()){
                best = max(ans, q.rbegin()->first + (time-1) * s);
            }

            int b = best - cost - (time-1) * s;
            st[idx] = b;
            q.insert({b, idx});
        } else {
            int best = q.rbegin()->first + (time) * s;
            ans = max(ans, best);

            q.erase({st[idx], idx});
        }
    }

    cout << ans << endl;
}

signed main()
{
    // bieo;
    int t=1;
    // cin >> t;

    while (t--) solve();
    
    return 0;
}