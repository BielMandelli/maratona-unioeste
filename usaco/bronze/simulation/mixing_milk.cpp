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
    vector<pair<int,int>> milk(3);

    for(auto &x : milk) cin >> x.first >> x.second;

    for (int i = 0; i < 100; i++)
    {
        int mx = milk[(i+1)%3].first - milk[(i+1)%3].second;

        int diff = mx - milk[i%3].second;

        if(diff >= 0) {
            milk[(i+1)%3].second += milk[i%3].second;
            milk[i%3].second = 0;
        }
        else {
            milk[(i+1)%3].second += milk[i%3].second + diff;
            milk[i%3].second -= milk[i%3].second + diff;
        }
    }
    
    for(auto x : milk) cout << x.second << endl;
}

signed main(){
    fastio;
    int cases = 1;
    //cin >> cases;
    for (int i = 0; i < cases; i++){
        solution();
    }
    
}
