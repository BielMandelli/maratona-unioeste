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

vector<ll> a;

ll get(int i) {
  return max(0ll, max(a[i - 1], a[i + 1]) - a[i] + 1);
}

void solution(){
    int n;
    cin >> n;
    a.resize(n+1);
    for(int i = 1; i <= n; i++) cin >> a[i];

    ll ans = 0;
    if(n%2){
        for (int i = 2; i < n; i+=2) ans += get(i);
        cout << ans << endl;
        return;
    }

    ll ans2 = 0;
    for (int i = 2; i < n; i+=2) ans2 += get(i);

    ans = ans2;
    for (int i = n-1; i > 1; i-=2)
    {
        ans2 -= get(i-1);
        ans2 += get(i);
        ans = min(ans, ans2);
    }
     
    cout << ans << endl;
    a.clear();
}

signed main(){
    fastio;
    int t=1;
    cin >> t;
    for (int i=0; i<t; i++){
        solution();
    }
}