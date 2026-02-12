#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) ((int) (a).size())
#define ll long long
#define ld long double

void dbg_out(string s) { cerr << endl; }
template<typename H, typename... T>
void dbg_out(string s, H h, T... t){
    do{ cerr << s[0]; s = s.substr(1);
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

    pair<int,int> init, end;
    cin >> init.first >> init.second >> end.first >> end.second;

    int mxx = 0, mnx = 1e9;
    vector<pair<int,int>> p(n); 
    map<int,int> cntx;
    for (int i=0; i<n; i++){
        cin >> p[i].first;
        mxx = max(p[i].first, mxx);
        mnx = min(p[i].first, mnx);
    }

    for (int i=0; i<n; i++){
       cin >> p[i].second;
    }

    sort(all(p));

    map<int, pair<int,int>> mpl;
    for (int i = 0; i < n; i++)
    {
        auto [x,y] = p[i];
        // cout << "saving y " << y << endl;
        int cur = mpl[x].first;
        if(cur == 0) mpl[x].first = y;
        mpl[x] = {min(mpl[x].first, y), max(mpl[x].first, y)};
    }
    
    int ans = 0;
    
    if(mnx != init.first) {
        auto [b, u] = mpl[mnx];
        ans += min({abs(u-init.second), abs(b-init.second)}) + abs(mnx - init.first);
    } else {
        auto [b, u] = mpl[mnx];
        ans += min({abs(u-init.second), abs(b-init.second)});
    }
    cout << "pb " << ans << endl;

    if(mxx != end.first) {
        auto [b, u] = mpl[mxx];
        cout << b << " " << u << endl;
        cout << mxx << " " << end.first << endl;
        ans += min({abs(u-end.second), abs(b-end.second)}) + abs(mxx - end.first);
    } else {
        auto [b, u] = mpl[mxx];
        ans += min({abs(u-end.second), abs(b-end.second)});
    }

    cout << "pre-end " << ans << endl;

    int lastu = -1, lastb = -1, lastx = -1;
    for (auto [x, ub] : mpl){
        auto [b, u] = ub;

        cout << "u: " << u << " b: " << b << endl;
        ans += abs(u-b);
        cout << "line dist " << abs(u-b) << endl;

        int mindist = 1e12;

        if(lastu >= 0){
            mindist = min({abs(u-lastu), abs(u-lastb), abs(b-lastu), abs(b-lastb)}) + abs(x - lastx);
            ans += mindist;
        };
        lastx = x;
        lastu = u;
        lastb = b;
    }

    cout << ans << endl;
}

signed main(){
    fastio;
    int cases=1;
    cin >> cases;
    for (int i=0; i<cases; i++){
        solution();
    }
}