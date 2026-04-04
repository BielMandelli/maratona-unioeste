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

void solution(){
    int n;
    cin >> n;

    int mx[2] = {-1, -1}, mn[2] = {100000000, 100000000};
    vector<vector<char>> m(n, vector<char> (n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> m[i][j];
            if(m[i][j] == '*') {
                mx[0] = max(i, mx[0]);
                mx[1] = max(j, mx[1]);
                mn[0] = min(i, mn[0]);
                mn[1] = min(j, mn[1]);
            }
        }
    }
    
    dbg(mx[0], mx[1], mn[0], mn[1]);
    int l,h;
    l = mx[1] - mn[1] + 1;
    h = mx[0] - mn[0] + 1;

    int ans = l*h;

    cout << ans << endl;
}

signed main(){
    fastio;
    int cases = 1;
    //cin >> cases;
    for (int i = 0; i < cases; i++){
        solution();
    }
    
}
