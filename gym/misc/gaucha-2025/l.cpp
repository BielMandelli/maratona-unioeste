#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define ll long long
#define sz(a) ((int)(a).size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define int long long
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

    vector<int> a(n);
    bool alleq = true;
    int last = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(last && last != a[i]) alleq = false;
        last = a[i];
    }
    
    sort(all(a));
    int mx = *max_element(all(a));
    if(a[n-1] != a[n-2]) cout << a[n-1] << endl;
    else {
        int ans = 1e18;
        for (int i = 0; i < n-1; i++)
        {
            auto idx = lower_bound(a.begin()+i+1, a.end(), a[n-1]+1-a[i]);
            ans = min(ans, a[i]+*idx);
        }
        cout << (ans != 1e18 ? ans : -1) << endl;
    }
}

signed main(){  
    fastio;
    int t=1;
    //cin >> t;
    for (int i=0; i<t; i++) solve();
}