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
    int n,m,k;
    cin >> n >> m >> k;

    vector<int> a(n);
    map<int,int> pos;
    int i = 0;
    for(auto &x : a) {
        cin >> x;
        pos[x] = i;
        i++;
    }
    
    map<int,int> ord;
    for (int i = 0; i < k; i++)
    {
        int x,y;
        cin >> x >> y;
        ord[y] = x;
    }
    
    int ans = 1, cur = 0, dist;
    for (int i = 1; i <= n; i++)
    {
        if(ord[i]) ans =   ;
        else {
            if(ord[i])
        }
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
