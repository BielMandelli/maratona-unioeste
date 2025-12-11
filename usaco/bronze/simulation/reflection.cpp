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
int ans = 0;
int n, q;
vector<string> g;
vector<vector<int>> sts;
void apply(int i, int j, int diff){
    if(g[i][j] == '.') return;

    i = min(i, n-1-i);
    j = min(j, n-1-j);

    ans -= min(sts[i][j], 4-sts[i][j]);
    sts[i][j] += diff;
    ans += min(sts[i][j], 4-sts[i][j]);
}

void solution(){
    cin >> n >> q;
    g.resize(n);
    for(auto &x : g) cin >> x;

    sts.resize(n/2, vector<int>(n/2));
    for (int i = 0; i < n; i++) for(int j = 0; j < n; j++) apply(i, j, 1);
    
    cout << ans << endl;

    while(q--){
        int r,c;
        cin >> r >> c;
        r--; c--;
        apply(r, c, -1);
        g[r][c] = '#' + '.' - g[r][c];
        apply(r, c, 1);
        cout << ans << endl;
    }
}

signed main(){
    fastio;
    int cases = 1;
    //cin >> cases;
    for (int i = 0; i < cases; i++){
        solution();
    }
    
}
