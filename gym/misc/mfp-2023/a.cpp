#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<int> p(n+1);

    for (int i = 1; i <= n; i++) cin >> p[i];
    

    for (int i = 1; i < n+1; i++)
    {
        vector<int> ans;

        ans.push_back(i);
        int cur = p[i];

        while (cur != i)
        {
            ans.push_back(cur);
            cur = p[cur];
        }
        
        for(auto a : ans) cout << a << " ";
        cout << endl;
    }
    
}

signed main() {
    bieo;
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}