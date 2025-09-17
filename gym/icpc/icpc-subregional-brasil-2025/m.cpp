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

#define int long long

void solution(){
    int n,k;
    cin >> n >> k;

    vector<int> a(n);
    for(auto &x : a) cin >> x;

    int l = 1, r = *max_element(all(a)) + k + 1, ans = 0;
    while(l < r){
        int m = l + (r - l) / 2;
        bool valid = true;
        int mnj = 0;      
        int mxj = n - 1;   

        for (int i = 0; i < n; ++i) {
            if (a[i] < m) {
                int rm = m - a[i];
                if (rm > k) { valid = false; break; }
                mnj = max(mnj, i);
                mxj = min(mxj, i + k - rm);
            }
        }
        
        if (valid && mnj <= mxj) {
            ans = m; 
            l = m + 1;
        } else  r = m;
    }

    cout << ans << endl;
}

signed main(){
    fastio;
    int t=1;
    //cin >> t;
    for (int i=0; i<t; i++){
        solution();
    }
}