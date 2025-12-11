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
const int M = 1e9+7;

void solution(){
    string s;
    cin >> s;

    string s2;
    for (int i = 0; i < s.size(); i++)
    {
        if(s[i] != 'a' && s[i] != 'b') continue;
        s2.push_back(s[i]);
    }
    
    int cur = 1;
    vector<int> cnt;
    for (int i = 1; i < s2.size(); i++)
    {
        if(s2[i] == s2[i-1]) cur++;
        else {
            if(s2[i-1] == 'a') cnt.push_back(cur);
            cur = 1;
        }
    }
    
    if(s2.back() == 'a') cnt.push_back(cur);
    
    int ans = 0;
    ans = 1;
    for (int i = 0; i < cnt.size(); i++) {
        ans *= cnt[i]+1; 
        ans %= M;
    }
    
    cout << ans-1 << endl;
}

signed main(){
    fastio;
    int cases = 1;
    //cin >> cases;
    for (int i = 0; i < cases; i++){
        solution();
    }
    
}
