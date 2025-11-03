#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bieo cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
int n, ans = 0;
vector<vector<pair<int,int>>> tree;
vector<vector<int>> aut;
vector<int> edges, p;
string st, s;

void calc_kmp(char ch){
    s.push_back(ch);

    int i = s.size() - 1;

    for (int c = 0; c < 26; c++){
        if(i > 0 && 'a' + c != ch) aut[i][c] = aut[p[i-1]][c];
        else aut[i][c] = i + (s[i] == ('a' + c));
    }
}

void dfs(int node){
    for (auto [c, e] : tree[node]){                  
        calc_kmp(c);
        int n = s.size();
        int j = (n >= 2 ? aut[p[n-2]][c - 'a'] : 0);                   
        p.push_back(j);            
        int k = n - j;                                                 
        if(k && j && (n % k == 0)) ans= max(ans, k);            
        dfs(e);
        s.pop_back();
        p.pop_back();
    }            
    if(s.size()){
        aut.pop_back();
    }
}

void solve(){
    cin >> n;

    tree.resize(n);
    edges.resize(n-1);
    aut.resize(n, vector<int>(26));
    for(auto &x : edges) cin >> x;

    cin >> st;

    for (int i = 0; i < n-1; i++)
    {
        int u = edges[i];
        u--;
        tree[u].push_back({st[i], i+1});
    }

    for (int i = 0; i < n; i++) sort(tree[i].begin(), tree[i].end());
    
    dfs(0);

    cout << ans << endl;
}

signed main() {
    bieo;
    int t = 1;
    //cin >> t;
    while (t--) solve();

    return 0;
}
