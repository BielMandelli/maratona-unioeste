#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

void solve(){
    int n;
    cin >> n;

    vector<int> a(n), cnt(n+1);
    for(auto &x : a) {
        cin >> x;
    }

    sort(a.begin(), a.end());

    int best = a[n/2],ans = 0;
    for (int i = 0; i < n; i++)
    {
        if(a[i] != best) ans += abs(a[i]-best);
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