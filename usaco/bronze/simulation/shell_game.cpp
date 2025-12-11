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

vector<pair<pair<int,int>, int>> v;
int sim(int x){

    int ans = 0;
    for(auto [mv, g] : v){
        auto [a, b] = mv;

        if(x == a) x = b;
        else if(x == b) x = a;

        if(g == x) ans++;
    }

    return ans;
}

void solution(){
    int n;
    cin >> n;
    v.resize(n);

    for(auto &x : v) cin >> x.first.first >> x.first.second >> x.second;

    int ans = 0;
    ans = max(ans, sim(1));
    ans = max(ans, sim(2));
    ans = max(ans, sim(3));

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
