#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bieo cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

signed main() {
    bieo;
    int n, m;
    cin >> n >> m;

    vector<int> s(n);
    for (auto &x : s) cin >> x;

    int cur = 0;
    for (int i = 0; i < n; i++)
    {
        cur = max(s[i], cur-m);
        s[i] = cur;
    }

    cur = 0;
    for (int i = n-1; i >= 0; i--)
    {
        cur = max(s[i], cur-m);
        s[i] = cur;
    }
    
    for (auto x : s) cout << x << " ";
    cout << endl;
    
    return 0;
}
