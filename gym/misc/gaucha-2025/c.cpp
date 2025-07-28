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
    vector<int> a(n);
    for (int i=0; i<n; i++){
        cin>>a[i];
    }

    int ans = 1, cur = *a.begin();
    for (int i = 0; i < 2*n; i++)
    {
        cur = min(cur, a[i%n]);
        a[i%n] = cur;
        cur++;
    }

    cur = *a.begin();
    for (int i = 0; i < 2*n; i++)
    {
        cur = min(cur, a[(n-i+n)%n]);
        a[(n-i+n)%n] = cur;
        cur++;
    }
    
    
    cout << *max_element(all(a)) << endl;
}

signed main(){  
    fastio;
    int t=1;
    //cin >> t;
    for (int i=0; i<t; i++) solve();
}