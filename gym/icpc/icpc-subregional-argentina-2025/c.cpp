#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) (int) (a).size()
#define ll long long
#define ld long double

void dbg_out(string s) { cerr << endl; }
template<typename H, typename... T>
void dbg_out(string s, H h, T... t){
    do { cerr << s[0]; s = s.substr(1);
    } while (sz(s) && s[0] != ',');
    cerr << " = " << h;
    dbg_out(s, t...);
}

#ifdef DEBUG
#define dbg(...) dbg_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 42
#endif

#define int long long

void solve(){
    int n, x;
    cin >> n;
    vector<int> cnt(n);
    for (int i=1; i<=n; i++) {
        cin >> x;
        int r = (i+x)%n;
        cnt[r]++;
    }
    
    int ans = 0;
    for(auto v : cnt) ans += v * v;

    cout << ans << '\n';
}

signed main(){
    fastio;
    int t=1;
    //cin >> t;
    for (int i = 0; i < t; i++)
    {
        solve();
    }
    return 0;
}