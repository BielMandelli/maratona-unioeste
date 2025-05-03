#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bieo cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

signed main() {
    bieo;
    int n, w;
    cin >> n >> w;
    vector<int> st(n);

    for(auto &x : st) cin >> x;

    int temp = 0, mi = 1e9, ma = -1e9, l, r;
    for (int i = 0; i < n; i++)
    {
        temp += st[i];
        mi = min(mi, temp);
        ma = max(ma, temp);
    }
    
    if(mi < 0) l = -mi;
    else l = 0;

    if(ma <= 0) r = w;
    else r = w - ma;
        
    if(l > r or ma > w) cout << 0 << endl;
    else cout << r - l + 1 << endl;
    
    return 0;
}
