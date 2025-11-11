#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fastio cin.tie(0)->sync_with_stdio(0)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) ((int) (a).size())
#define ld long double

void dbg_out(string s) { cerr << endl; }
template<typename H, typename... T>
void dbg_out(string s, H h, T... t){
    do { cerr << s[0]; s = s.substr(1);
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
    cin >> n;
    deque<int> odd;
    
    int ans = 0;
    for(int i = 0, x; i < n; i++) {
        cin >> x;
        if(x%2) odd.push_back(x);
        else ans += x;
    }


    sort(all(odd));

    bool have = odd.empty();

    while(!odd.empty()){
        ans += odd.back();
        odd.pop_back();
        if(odd.empty()) break;
        odd.pop_front();
    }

    if(have) cout << 0 << endl;
    else cout << ans << endl;
}

signed main(){
    int cases = 1;
    cin >> cases;
    for (int i=0; i<cases; i++){
        solution();
    }
    
}
