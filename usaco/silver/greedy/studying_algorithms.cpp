#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

void solve(){
    int n,x;
    cin >> n >> x;

    vector<int> a(n);
    for(auto &x : a) cin >> x;

    sort(a.begin(), a.end());
    int ans = 0, cur = 0;
    for (int i = 0; i < n; i++)
    {
        if(cur+a[i] <= x) {
            ans ++; 
            cur+=a[i];
        } else break;
    }
    
    cout << ans << endl;
}

signed main()
{
    bieo;
    int t=1;
    // cin >> t;

    while (t--) solve();
    
    return 0;
}