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
    vector<int> a(4);
    for(auto &x : a) cin >> x;

    for (int i = 0; i < 4; ++i) {
        vector<int> t;
        for (int j = 0; j < 4; ++j) if (j != i) t.push_back(a[j]);
        if (t[0] < t[1] && t[1] < t[2]) {
            cout << t[0] << ' ' << t[1] << ' ' << t[2] << endl;
            return;
        }
    }
    cout << "ALLENDE VIVE" << endl;
}

signed main(){
    fastio;
    int cases = 1;
    //cin >> cases;
    for (int i = 0; i < cases; i++){
        solution();
    }
    
}
