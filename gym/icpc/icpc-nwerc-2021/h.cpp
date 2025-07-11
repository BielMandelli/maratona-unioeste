#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

bool can(int x, vector<int> p) {
    int n = p.size();

    for (int i = 0; i < n; i++) {
        int cur = x;
        if (cur < p[i]) continue;

        cur += p[i];
        int l = (i - 1 + n) % n;
        int r = (i + 1) % n;

        vector<bool> visited(n, false);
        visited[i] = true;

        int cnt = 1;

        while (cnt < n) {
            bool move = false;

            if (!visited[l] && p[l] <= cur) {
                cur += p[l];
                visited[l] = true;
                cnt++;
                l = (l - 1 + n) % n;
                move = true;
            }

            else if (!visited[r] && p[r] <= cur) {
                cur += p[r];
                visited[r] = true;
                cnt++;
                r = (r + 1) % n;
                move = true;
            }

            if (!move) break;
        }

        if (cnt == n) return true;
    }

    return false;
}

void solve(){
    int n;
    cin >> n;
    vector<int> p(n);
    int mx = 0;
    for(auto &x : p){
        cin >> x;
        mx = max(x, mx);
    }

    int l = 0, r = 1e14;
    while (l < r)
    {
        int m = (l+r)/2;
        if(can(m, p)) r = m;
        else l = m+1;
    }
    
    cout << l << endl;
}

signed main()
{
    bieo;
    int t=1;
    // cin >> t;

    while (t--) solve();
    
    return 0;
}