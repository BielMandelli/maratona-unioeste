#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define ld long double
#define sz(a) ((int) (a).size())

void dbg_out(string s) { cerr << endl; }
template<typename H, typename... T>
void dbg_out(string s, H h, T... t){
    do { cerr << s[0]; s = s.substr(1);
    } while (sz(s) && s[0] != ',');
    cerr << " = " << h;
    dbg_out(s, t...);
}

#ifdef DEBUG
#define dbg(...) dbg_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 42
#endif

bool possible(int x, int y, int z) {
    for (int i = 0; i < 31; i++) {
        int bx = (x >> i) & 1;
        int by = (y >> i) & 1;
        int bz = (z >> i) & 1;
        if (!((bx == 0 && by == 0 && bz == 0) ||
            (bx == 0 && by == 1 && bz == 0) ||
            (bx == 0 && by == 0 && bz == 1) ||
            (bx == 1 && by == 0 && bz == 0) ||
            (bx == 1 && by == 1 && bz == 1)
        )) return false;
    }
    return true;
}

void solution(){
    int x, y, z;
    cin >> x >> y >> z;
    cout << (possible(x, y, z) ? "YES" : "NO") << endl;
}

signed main(){
    int cases = 1;
    cin >> cases;
    for(int i = 0; i < cases; i++) solution();
    return 0;
}