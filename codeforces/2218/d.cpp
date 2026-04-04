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

const int MAXX = 1e6;
int fac[MAXX];
vector<ll> primes;

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
}

void solution(){
    int n;
    cin >> n;

    vector<int> a(n);

    if (n == 2) {
        cout << 1 << " " << 1 << endl;
        return;
    }

    a[0] = primes[0];
    for (int i = 1; i <= n - 2; i++) {
        a[i] = primes[i - 1] * primes[i];
    }
    a[n - 1] = primes[n - 2];

    for(auto x : a) cout << x << ' ';
    cout << endl;
}

signed main(){
    fastio;
    sieve(1e6);
    int cases=1;
    cin >> cases;
    for (int i=0; i<cases; i++){
        solution();
    }
}