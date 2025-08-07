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
vector<vector<char>> g;
vector<vector<set<int>>> c;
vector<string> s;
map<string, int> mp;
int n, m, p;

void checkLine(int i, int j){
    string sn = "";
    for (int k = j; k < m; k++)
    {
        sn += g[i][k];
        sort(all(sn));
        for (int o = 0; o < p; o++)
        {
            if(sn == s[o]) for (int l = j; l <= k; l++) c[i][l].insert(o);
        } 
    }
}

void checkColumn(int i, int j){
    string sn = "";
    for (int k = i; k < n; k++)
    {
        sn += g[k][j];
        sort(all(sn));
        for (int o = 0; o < p; o++)
        {
            if(sn == s[o]) for (int l = i; l <= k; l++) c[l][j].insert(o);
        }
        
    }
}

void checkDiag(int i, int j){
    string sn = "";
    for (int k = i, l = j; k < n && l < m; k++, l++)
    {
        sn += g[k][l];
        sort(all(sn));
        for (int o = 0; o < p; o++)
        {
            if(sn == s[o]) for (int a = i, b = j; a <= k && b <= l; a++, b++) c[a][b].insert(o);
        }
    }
}

void checkRevDiag(int i, int j){
    string sn = "";
    for (int k = i, l = j; k >= 0 && l < m; k--, l++)
    {
        sn += g[k][l];
        sort(all(sn));
        for (int o = 0; o < p; o++)
        {
            if(sn == s[o]) for (int a = i, b = j; a >= k && b <= l; a--, b++) c[a][b].insert(o);
        }
    }
}

void solve(){
    cin >> n >> m;
    g.resize(n, vector<char>(m));
    c.resize(n, vector<set<int>>(m));
    for (int i=0; i<n; i++){
        for (int j = 0; j < m; j++)
        {
            cin >> g[i][j];
        }
    }

    cin >> p;
    s.resize(p);
    for (int i = 0; i < p; i++)
    {
        cin >> s[i];
        sort(s[i].begin(), s[i].end());
        mp[s[i]] = i+1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            checkLine(i,j);
            checkColumn(i,j);
            checkDiag(i,j);
            checkRevDiag(i,j);
        }
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(c[i][j].size() > 1) ans++;
        }
    }
    
    cout << ans << endl;
}

signed main(){
    fastio;
    int t=1;
    //cin >> t;
    for (int i=0; i<t; i++) solve();
}