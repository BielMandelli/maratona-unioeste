#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

void solve(){
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n), ap(m);
    for(auto &x : a) cin >> x;
    for(auto &x : ap) cin >> x;

    sort(a.begin(), a.end());
    sort(ap.begin(), ap.end());

    int ans = 0;
    for (int i = 0, j = 0; i < n && j < m;)
    {
        // cout << a[i] << " " << ap[j] << endl;
        if(ap[j]-k <= a[i] && a[i] <= ap[j]+k) {
            ans++;
            i++;
            j++;
        }
        else if(a[i] < ap[j]) i++;
        else j++;
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