#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) (int) (a).size()
#define ll long long
#define ld long double
#define pb push_back

typedef long long C;
typedef complex<C> P;
#define X real()
#define Y imag()

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

void solution(){
    int t,d,m;
    cin >> t >> d >> m;

    vector<int> times, a(m);
    int cur = 0;
    for(int i = 0; i < m; i++){
        cin >> a[i];
    }

    for(int i = 0; i < m; i++){
        int dif = a[i] - cur;
        times.push_back(dif);
        cur = a[i];
    }
    times.push_back(d-cur);

    bool ans = false;
    for(auto x : times) {
        // dbg(x);
        if(x >= t) ans = true;
    }
    
    cout << (ans or (!m && t <= d) ? "Y" : "N") << endl;
}

signed main(){
    fastio;
    int t=1;
    //cin >> t;
    for (int i=0; i<t; i++){
        solution();
    }
}