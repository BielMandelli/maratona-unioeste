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

#define int long long
const int MOD = 676767677;

void solution(){
    int n, m;
    cin >> n >> m;

    vector<int> b(n), cnt(m);

    for (auto &x : b) {
        cin >> x;
        cnt[x]++;
    }

    vector<int> psum(m+1);
    for (int i = 1; i <= m; i++) psum[i] = psum[i-1] + cnt[i-1];
    
    int ans = 1;
    bool valid = true;

    for (int i = 0; i < n; i++) {
        int cur = b[i];

        if (cur == 0) continue;

        int mn = 1e14;
        if (i > 0) mn = min(mn, b[i-1]);    
        if (i+1 < n) mn = min(mn, b[i+1]);

        if (mn >= cur) {
            valid = false;
            break;
        }

        if (mn == cur-1) ans = (ans * psum[cur]) % MOD;
        else ans = (ans * cnt[cur-1]) % MOD;
        
    }

    cout << (valid ? ans : 0) << endl;
}

signed main(){
    fastio;
    int cases=1;
    cin >> cases;
    for (int i=0; i<cases; i++){
        solution();
    }
}