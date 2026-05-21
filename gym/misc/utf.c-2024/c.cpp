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

    set<string> s;
    map<string, int> mp;

    for (int i = 0; i < n; i++)
    {
        string ss;
        cin >> ss;
        s.insert(ss);
        mp[ss] = 0;
    }
    
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string ss;
        cin >> ss;
        if(s.count(ss) == 0) continue;
        mp[ss]++;
    }
    
    for(auto [k,v] : mp){
        cout << k << " " << v << endl;
    }
}

signed main(){
    fastio;
    int cases = 1;
    //cin >> cases;
    for (int i = 0; i < cases; i++){
        solution();
    }
    
}
