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

void solution(){
    int n, q;
    cin >> n >> q;

    vector<int> a(n), b(n), f(n);
    
    for(auto &x : a) cin >> x;
    for(auto &x : b) cin >> x;

    for (int i = n-1; i >= 0; i--)
    {
        a[i] = max(a[i], b[i]);
        f[i] = max(f[i], a[i]);
        if(i+1 < n) {
            f[i] = max(f[i], a[i+1]);
            a[i] = max(a[i], a[i+1]);
        }
        // cout << f[i] << endl;
    }
    
    vector<int> psum(n+1);
    for (int i = 1; i <= n; i++)
    {
        psum[i] += f[i-1] + psum[i-1];
    }
    
    while (q--)
    {
        int l,r;
        cin >> l >> r;

        cout << psum[r] - psum[l-1] << ' ';
    }
    cout << endl;
}

signed main(){
    fastio;
    int cases=1;
    cin >> cases;
    for (int i=0; i<cases; i++){
        solution();
    }
}