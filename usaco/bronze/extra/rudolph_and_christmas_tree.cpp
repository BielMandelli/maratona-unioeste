#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define ll long long 
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) ((int) (a).size())
#define ld long double

void dbg_out(string s) {cerr << endl;}
template<typename H, typename ...T>
void dbg_out(string s, H h, T... t){
    do{cerr << s[0]; s = s.substr(1);
    } while(sz(s) && s[0] != ',');
    cerr << " = " << h;
    dbg_out(s, t...);
}

#ifdef DEBUG
#define dbg(...) dbg_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 42
#endif

void solution(){
    ld n, b, h;
    cin >> n >> b >> h;

    vector<ld> a(n);
    for(auto &x : a) cin >> x;

    sort(all(a));

    ld ans = b*h/2.0;
    for (int i = 0; i < n-1; i++)
    {
        if(a[i+1] >= a[i]+h) ans += b*h/2.0;
        else {
            ld b2 = b*(a[i]+h - a[i+1])/h;
            ld diff = a[i+1] - a[i];
            ans += (b+b2)/2.0*diff;
        }
    }
    
    cout << setprecision(12) << fixed;
    cout << ans << endl;
}

signed main(){
    fastio;
    int cases = 1;
    cin >> cases;
    for (int i = 0; i < cases; i++){
        solution();
    }
    
}
