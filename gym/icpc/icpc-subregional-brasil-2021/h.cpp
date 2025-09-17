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
    int n,k;
    cin >> n >> k;

    vector<pair<int,int>> a(n);
    vector<int> pos;
    for(auto &x : a) {
        cin >> x.first >> x.second;
        pos.push_back(x.second);
    }

    sort(a.begin(), a.end());
    bool ans = true;
    for(int i = 0; i < n; i++){
        if(pos[i] != a[i].second) ans = false;
    }

    cout << (ans ? "Y" : "N") << endl;
}

signed main(){
    fastio;
    int t=1;
    //cin >> t;
    for (int i=0; i<t; i++){
        solution();
    }
}