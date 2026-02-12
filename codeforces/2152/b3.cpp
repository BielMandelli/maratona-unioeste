#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define ll long long
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) ((int) (a).size())
#define ld long double

void dbg_out(string s) {  cerr << endl; }
template<typename H, typename...T>
void dbg_out(string s, H h, T... t){
    do {cerr << s[0]; s = s.substr(1);
    } while (sz(s) && s[0] != ',');
    cerr << " = " << h;
    dbg_out(s, t...);
}

#ifdef DEBUG
#define dbg(...) dbg_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 42
#endif

void solution(){
    ll n;
    cin >> n;

    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    ll ans = 0;
    ll bk = min({n-y1, n-x1, x1, y1});
    ll bd = min({n-y2, n-x2, x2, y2});

    if(bk < bd) cout << -1 << endl;
    else {
        ans = max(abs(x2-x1), abs(y2-y1));
        cout << ans <<
    }
}

signed main(){
    // fastio;
    int cases = 1;
    cin >> cases;
    for (int i = 0; i < cases; i++)
    {
        solution();
    }
}