#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define ll long long
#define sz(a) ((int)(a).size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

#define DEBUG

void debug_out(string s, int line) { cerr << endl; }
template<typename H, typename... T>
void debug_out(string s, int line, H h, T... t){
    if (s[0] != ',') cerr << "Line(" << line << ") ";
    do{ cerr << s[0]; s = s.substr(1);
    } while (s.size() and s[0] != ',');
    cerr << " = " << h;
    debug_out(s, line, t...);
}

#ifdef DEBUG
#define dbg(...) debug_out(#__VA_ARGS__, __LINE__, __VA_ARGS__)
#else
#define dbg(...) 42
#endif

void solve(){
    int n;
    cin >> n;
    vector<int> p(n), o(n);
    for (int i=0; i<n; i++){
        cin >> o[i];
        p[i] = o[i];
    }

    sort(p.rbegin(), p.rend());
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if(p[i] == o[i]) ans++;
    }

    cout << ans << endl;
    
    
}

signed main(){
    fastio;
    int t=1;
    cin >> t;
    for (int i=0; i<t; i++) solve();
}