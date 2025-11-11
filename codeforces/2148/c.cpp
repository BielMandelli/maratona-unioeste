#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fastio cin.tie(0)->sync_with_stdio(0)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) ((int) (a).size())
#define ld long double

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

void solution(){
    int n,m;
    cin >> n >> m;
    vector<pair<int,int>> a(n);
    for(auto &x : a) cin >> x.first >> x.second;
    int ans = 0, cur = 0, goal = a[0].first, side = 0;
    for (int i = 0; i < n; i++)
    {   
        int diff = abs(cur - a[i].first);
        dbg(cur, a[i].first);
        if(a[i].second != side){
            if(diff % 2) ans += diff;
            else ans += diff -1;
        } else {
            if(!(diff % 2)) ans += diff;
            else ans += diff -1;
        }

        dbg(diff, ans);

        cur = a[i].first; 
        goal = (i+1 < n ? a[i+1].first : m); 
        side = a[i].second;
    }

    ans += m - a[n-1].first;
    
    cout << ans << endl;
}

signed main(){
    int cases = 1;
    cin >> cases;
    for (int i=0; i<cases; i++){
        solution();
    }
    
}
