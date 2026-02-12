#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define ll long long
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) ((int) (a).size())
#define ld long double

void dbg_out(string s) {  cerr << endl; }
template<typename H, typename...T>
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

void solution(){
    ll n,q;
    cin >> n >> q;

    vector<int> a(n);
    int cnt = 0, st, en, last = -1;
    vector<pair<int,int>> interval;
    for(int i = 0, x; i < n; i++) {
        cin >> x;
        a[i] = x;

        if(x != last && i){
            if(cnt == 0) st = i;
            cnt++;
        } else if (cnt >= 5){
            en = i;
            cnt = 0;
            interval.push_back({st, en});
            st = -1, en = -1;
        } else cnt = 0;

        last = x;
    }

    if(en != -1) interval.push_back({st, en});

    for(auto [x,y] : interval) dbg(x, y);
    vector<int> pref0(n+1), pref1(n+1);
    for (int i = 1; i <= n; i++)
    {
        pref0[i] = pref0[i-1] + (a[i-1] == 0);
        pref1[i] = pref1[i-1] + (a[i-1] == 1);
    }
    
    while(q--){
        int l,r;
        cin >> l >> r;
        int cnt0 = pref0[r] - pref0[l-1];
        int cnt1 = pref1[r] - pref1[l-1];
        
        int plus = 0;
        
        for(auto [x,y]: interval){
            if(x <= l && r <= y) plus = 1;
        }
        // dbg(cnt0, cnt1);
        if(cnt0 % 3 or cnt1 % 3) cout << -1 << endl;
        else {
            cout << (cnt0+cnt1)/3 + plus << endl;
        }
    }
}

signed main(){
    // fastio;
    int cases = 1;
    cin >> cases;
    for (int i = 0; i < cases; i++)
    {
        solution();
    }
}