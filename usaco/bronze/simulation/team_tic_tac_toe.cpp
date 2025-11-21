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
    vector<vector<char>> m(3, vector<char>(3)); 
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> m[i][j];

    set<pair<char,char>> sing, gr;
    for (int i = 0; i < 3; i++)
    {
        set<char> c, r, d;
        for (int j = 0; j < 3; j++)
        {
            r.insert(m[i][j]);
            c.insert(m[j][i]);
            if(!i) d.insert(m[j][j]);
            if(i == 2) d.insert(m[i-j][j]);
        }

        dbg(i, sz(r), sz(d), sz(c));

        if(sz(r) == 1) sing.insert({*r.begin(), *r.begin()});
        else if(sz(r) == 2) gr.insert({*r.begin(), *prev(r.end())});

        if(sz(c) == 1) sing.insert({*c.begin(), *c.begin()});
        else if(sz(c) == 2) gr.insert({*c.begin(), *prev(c.end())});

        if(sz(d) == 1) sing.insert({*d.begin(), *d.begin()});
        else if(sz(d) == 2) gr.insert({*d.begin(), *prev(d.end())});
    }

    for(auto [u,v] : gr) cout << u << v << endl;
    
    cout << sz(sing) << endl << sz(gr) << endl;
}

signed main(){
    fastio;
    int cases = 1;
    //cin >> cases;
    for (int i = 0; i < cases; i++){
        solution();
    }
    
}
