#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define ll long long
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) ((int) (a).size())
#define ld long double

void dbg_out(string s) {cerr << endl; }
template<typename H, typename... T>
void dbg_out(string s, H h, T... t){
    do {cerr << s[0]; s = s.substr(1);
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
    int n;
    string s;
    cin >> n >> s;
    vector<int> ind;
    for (int i = 0; i < n; i++)
    {
        if(s[i] == '1') ind.push_back(i+1);
    }
    
    cout << sz(ind) << endl;
    for(auto &x : ind) cout << x << " ";
    cout << endl;
}

signed main(){
    fastio;
    int t=1;
    cin >> t;
    for (int i=0; i<t; i++){
        solution();
    }
}