#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) ((int) (a).size())
#define ll long long
#define ld long double

void dbg_out(string s) { cerr << endl; }
template<typename H, typename... T>
void dbg_out(string s, H h, T... t){
    do{ cerr << s[0]; s = s.substr(1);
    } while (sz(s) && s[0] != ',');
    cerr << " = " << h;
    dbg_out(s, t...);
}

#ifdef DEBUG
#define dbg(...) dbg_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 42
#endif

void solution(){
    int x,y;
    cin >> x >> y;

    int n = x+y;

    bool valid = true;
    if (n%2) {
        if (x > n/2) valid = false;
    } else {
        if (x == 0 or x > n/2) valid = false;
    }

    if (!valid) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;

    if (n == 1) return;

    int len;
    if (n%2) len = 2*x;
    else len = (2*x) - 1;

    for (int i = 1; i <= len; i++) {
        cout << i << " " << i + 1 << endl;
    }

    for (int i = len + 2; i <= n; i++) {
        cout << 1 << " " << i << endl;
    }
}

signed main(){
    fastio;
    int cases=1;
    cin >> cases;
    for (int i=0; i<cases; i++){
        solution();
    }
}