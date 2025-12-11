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

struct f {
    int x,y,z,r;

};


void solution(){
    vector<f> a(2);

    for(auto &x : a) cin >> x.x >> x.y >> x.z >> x.r;

    int dx, dy, dz;
    dx = a[0].x - a[1].x;
    dy = a[0].y - a[1].y;
    dz = a[0].z - a[1].z;

    int dist = dx*dx + dy*dy + dz*dz;

    int r2 = (a[0].r + a[1].r) * (a[0].r + a[1].r);
    
    cout << (dist <= r2 ? "S" : "N") << endl; 
}

signed main(){
    fastio;
    int cases = 1;
    //cin >> cases;
    for (int i = 0; i < cases; i++){
        solution();
    }
    
}
