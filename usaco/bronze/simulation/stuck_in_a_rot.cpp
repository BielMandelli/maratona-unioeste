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

struct cow {
    int i,x,y;
};

bool compx(const cow &c1, const cow &c2){
    return c1.x < c2.x;
}

bool compy(const cow &c1, const cow &c2){
    return c1.y < c2.y;
}

void solution(){
    int n;
    cin >> n;
    vector<cow> north, east;
    for (int i = 0; i < n; i++)
    {
        int x,y;
        char c;
        cin >> c >> x >> y;
        if(c == 'N') north.push_back({i,x,y});
        else east.push_back({i,x,y});
    }
    
    sort(all(north), compx);
    sort(all(east), compy);

    vector<int> st(n, -1);
    for (auto nc : north){
        for(auto ec : east){
            if(nc.x > ec.x && nc.y < ec.y){
                int nd = ec.y - nc.y;
                int ed = nc.x - ec.x;

                if(nd < ed && st[ec.i] == -1) st[ec.i] = nc.x;

                if(nd > ed && st[ec.i] == -1) {
                    st[nc.i] = ec.y;
                    break;
                }
            }    
        }
    }

    vector<int> dist(n, -1);
    for(auto nc : north){
        if(st[nc.i] != -1) dist[nc.i] = st[nc.i] - nc.y;
    }

    for(auto ec : east){
        if(st[ec.i] != -1) dist[ec.i] = st[ec.i] - ec.x;
    }

    for(auto d : dist) cout << (d == -1 ? "Infinity" : to_string(d)) << endl;
}

signed main(){
    fastio;
    int cases = 1;
    //cin >> cases;
    for (int i = 0; i < cases; i++){
        solution();
    }
    
}
