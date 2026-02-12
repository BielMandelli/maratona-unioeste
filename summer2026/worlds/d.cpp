#include <bits/stdc++.h>
using namespace std;

#define ld long double
#define ll long long
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) ((int)(a).size())

const int MAXX = 1e6; 

int fac[MAXX];
vector<ll> primes;
vector<ll> mp(10);

bool valid(ll x){
    int cnt = 0;
    int l = -1, f = -1;
    fill(all(mp), 0);
    while(x > 0){
        int cur = x % 10;
        if(l < 0) l = cur;
        f = cur;
        mp[cur]++;
        x /= 10;
    } 

    if(l != 9) return 0;
    if(mp[4] > 1 or mp[1] or mp[3] or mp[5] or mp[7] or mp[2] or mp[8] or mp[0]) return 0;
    return 1;
    // cout << f << " " << l << endl;
}

void sieve(ll n){
    for (ll i=1; i<n; i++) fac[i] = i;
    for (ll i=2; i<n; i++){
        if (fac[i] == i) primes.push_back(i);
        for (auto p: primes){
            if (i*p >= n) break;
            fac[i*p] = p;
            if (i%p == 0) break;
        }
    }
}// linear sieve

void solve(){
    // int n;
    // cin >> n;

    for(auto p : primes){
        if(valid(p)) cout << p << endl;
    }
}

signed main(){
    sieve(MAXX);
    cin.tie(0)->sync_with_stdio(0);
    int cases = 1;
    //cin >> cases;
    for (int i=0; i<cases; i++) solve();
}