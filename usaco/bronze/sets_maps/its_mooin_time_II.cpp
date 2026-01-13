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

#define int long long

void solution(){
    int n;
    cin >> n;
    vector<int> a(n), cnt(n+1), psum(n+1), app(n+1), lst(n+1);
    int idx = 1;
    map<int, int> pr;
    for(auto &x : a) {
        cin >> x;
        if(!cnt[x]){
            app[x] = idx-1; 
            psum[idx] += psum[idx-1] + 1;
        } else {
            psum[idx] = psum[idx-1];
        }

        cnt[x]++;
        if(!lst[x]) lst[x] = idx-1;
        if(cnt[x] > 1) {
            pr[lst[x]] = x;
            lst[x] = idx-1;
        } 
        idx++;
    }
    
    int ans = 0;
    map<int, int> vis;
    for(auto [k,v] : pr){
        dbg(k , v, app[v], psum[k]);
        int self = (app[v]<k ? 1 : 0);
        vis[v] = max(vis[v], psum[k] - self);
        dbg(vis[v]);
    }
    
    for(auto [k,v] : vis) ans += v;

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
