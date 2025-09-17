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
    int n;
    cin >> n;

    int init = 0;
    for (int i = n, x; i >= 0; i--)
    {
        cin >> x;
        if(x) init |= (1 << i);
    }

    int ans = init, cnt = 0;
    while(ans > 1){
        if (ans & 1) { 
            ans = (ans ^ (ans << 1));
            ans ^= 1;
        } else ans >>= 1;
        
        cnt++;
    }
    
    cout << cnt << endl;
}

signed main(){
    fastio;
    int t=1;
    //cin >> t;
    for (int i=0; i<t; i++){
        solution();
    }
}