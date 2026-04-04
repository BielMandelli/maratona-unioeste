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

#define int long long

vector<vector<int>> g;
vector<int> cap;
int n;

void dfs(int u, int p){
    cap[u] = 1;
    for(auto v : g[u]){
        if(v != p) {
            dfs(v, u);
            cap[u] += cap[v];
        }
    }
}

int calc(int u){
    vector<int> cmp;
    int s = n-1, ch = 0;

    for(int v : g[u]){
        if(cap[v] < cap[u]){
            cmp.push_back(cap[v]);
            ch += cap[v];
        }
    }

    int parent = n - 1 - ch;
    if(parent > 0) cmp.push_back(parent);

    int sumcomp = 0;
    for (auto x : cmp) sumcomp += x * x;

    int ans = (s*s - sumcomp) / 2;
    return ans;
}

void solution(){
    cin >> n;

    g.resize(n+123);
    cap.resize(n+123);

    for (int i = 2; i <= n; i++)
    {
        int x;
        cin >> x;

        g[i].push_back(x);
        g[x].push_back(i);
    }

    dfs(1, -1);
    
    int ans = -1, node = 1;

    for (int i = 1; i <= n; i++)
    {
        int cur = calc(i);
        if(cur > ans){
            ans = cur;
            node = i;
        }
    }
    
    cout << node << endl;
}

signed main(){
    fastio;
    int cases = 1;
    //cin >> cases;
    for (int i = 0; i < cases; i++){
        solution();
    }
    
}
