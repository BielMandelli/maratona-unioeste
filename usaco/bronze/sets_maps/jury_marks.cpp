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
    int n, k;
    cin >> n >> k;

    vector<int> a(n), b(k);
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < k; i++) cin >> b[i];
    
    vector<int> psum(n+1);
    for (int i = 1; i <= n; i++) psum[i] = psum[i-1] + a[i-1];
    
    set<int> fix;
    for (int i = 1; i <= n; i++) fix.insert(b[0]-psum[i]);
    
    int ans = 0;
    for(auto f : fix){
        set<int> poss;
        for(int i = 1; i <= n; i++) poss.insert(f + psum[i]);

        bool valid = true;
        for(auto j : b) valid &= poss.count(j);

        ans += valid;
    }

    cout << ans << endl;
}

signed main(){
    fastio;
    int cases = 1;
    //cin >> cases;
    for (int i = 0; i < cases; i++){
        solution();
    }
    
}
