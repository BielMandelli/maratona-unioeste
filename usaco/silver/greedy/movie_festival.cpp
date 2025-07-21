#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

void solve(){
    int n;
    cin >> n;
    vector<pair<int,int>> a(n);
    for (int i = 0; i < n; i++)
    {
        int x,y;
        cin >> a[i].second >> a[i].first;
    }
    
    sort(a.begin(), a.end());

    int ans = 0, last = 0;
    for (int i = 0; i < n; i++)
    {
        if(last <= a[i].second) {
            last = a[i].first;
            ans++;
        }
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