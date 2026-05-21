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
    vector<int> a(n);
    for(auto &x : a) cin >> x;

    int l = 0, r = 1e9, ans;
    while(l<r){
        // cout << l << " " << r << endl;
        int m = (l+r+1)/2;
        int cnt = 0;
        bool can = false;
        for (int i = 0; i < n+1; i++)
        {
            if(cnt == m){
                can = true;
                break;
            } else if(i == n) break;

            if(a[i] >= m) cnt++;
            else cnt = 0;
        }
        
        if(can) l = m;
        else r = m-1;
    }
    
    cout << l << endl;
}

signed main(){
    fastio;
    int cases = 1;
    //cin >> cases;
    for (int i = 0; i < cases; i++){
        solution();
    }
    
}
