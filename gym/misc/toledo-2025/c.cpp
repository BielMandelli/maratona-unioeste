#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define ll long long
#define sz(a) ((int)(a).size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

void solve(){
    ll n, e, m;
    cin >> n >> e >> m;
    
    ll ans = 1;
    while(e){
        if(e%2) ans = ans * n % m;
        n = n*n%m;
        e /= 2;
    }
    
    cout << ans << endl;
}

signed main(){
    fastio;
    int t=1;
    //cin >> t;
    for (int i=0; i<t; i++) solve();
}