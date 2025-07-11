#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

void solve(){
    int n;
    cin >> n;

    map<string, int> l, r, a;
    set<string> types;
    
    for (int i = 0; i < n; ++i) {
        string s, t;
        int x;
        cin >> s >> t >> x;
        types.insert(s);
        if (t == "left") l[s] = x;
        else if (t == "right") r[s] = x;
        else a[s] = x;
    }

    int ans = 0;
    bool valid = false;

    for (auto t : types) {
        int lf = l[t];
        int rg = r[t];
        int any = a[t];

        if ((lf && rg) || (any >= 2)) valid = true;
        any = (any) ? 1 : 0;
        ans += max({lf, rg, any});
    }

    if (!valid) cout << "impossible" << endl;
    else cout << (ans + 1) << endl;
}

signed main()
{
    bieo;
    int t=1;
    // cin >> t;

    while (t--) solve();
    
    return 0;
}