#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) (int) (a).size()
#define ll long long
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
#define dbg(...) dbg_out(#__VA_ARGS__, __VA_ARGS___)
#else
#define dbg(...) 42
#endif

vector<int> ans;

int share(int n, int k){
    if(k == 0) return n;
    return n/k;
}

void add(int index, int x){
    ans[index] += x;
}

void solve(){
    int n, m;
    cin >> n >> m;
    ans.resize(n+1);
    for (int i=0; i<m; i++){
        int x,y;
        cin >> x >> y;
        vector<int> op(n);
        int d = 0;
        for (auto &o : op){
            cin >> o;
            if(o == 1) d++;
        }

        int grp;
        grp = share(x, d+1);
        if(grp >= y) add(n, grp);
        else {
            grp = share(x, d);
            add(n, y);
        }

        for (int j = 0; j < n; j++)
        {
            if(op[j] == 1) add(j, grp);
            else add(j, y);
        }
    }

    for(auto x : ans) cout << x << " ";
    cout << endl;
}

signed main(){
    fastio;
    int t=1;
    //cin >> t;
    for (int i = 0; i < t; i++)
    {
        solve();
    }
    return 0;
}