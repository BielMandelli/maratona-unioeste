#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

signed main() {
    fastio;
    
    ll t;
    cin >> t;

    while (t--)
    {
        ll n,k;
        cin >> n >> k;

        vector<ll> a(n);
        
        ll start = -1;
        for (ll i = 0; i < n; i++){
            cin >> a[i];
            start = max(start, a[i]);
        }

        sort(a.begin(), a.end());

        ll maxx = start + k - 1, minn = start;
        
        for (ll i = 0; i < n-1; i++)
        {
            ll cycle = (start - a[i]) / k;

            if(cycle%2) {
                ll limit = a[i] + ((cycle+1)*k);
                minn = max(minn, limit);
            } else{
                ll limit = a[i] + ((cycle+1)*k) - 1;
                maxx = min(maxx, limit);
            }
        }
        
        if(minn > maxx) cout << -1 << endl;
        else cout << minn << endl;
    }
    
    return 0;
}