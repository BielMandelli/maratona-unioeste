#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

void solve(){
    int n;
    cin >> n;

    vector<int> a(n);
    int mx = -1, mn = 1e9;
    for(auto &x : a) {
        cin >> x;
        mx = max(x, mx);
        mn = m

    int first = a[0], last = a[n-1];
    vector<bool> bs(n, false);
    bs[0] = true;
    bs[n-1] = true;
    for (int i = 1, j = n-1; i < n-1; i++, j--)
    {
        if(a[i] < first) {
            bs[i] = true;
            first = max(a[i], first);
        }
        
        if(a[j] > last) {
            bs[i] = true;
            last = min(a[j], last);
        }
    }
    
    for (int i = 0; i < n; i++) cout << (bs[i] ? "1" : "0");
    cout << endl;
}

signed main()
{
    bieo;
    int t=1;
    cin >> t;

    while (t--) solve();
    
    return 0;
}