#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define ld long double
#define sz(a) ((int) (a).size())

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

#define endl '\n'

void solution(){
    ll n;
    cin >> n;

    vector<ll> s(n);
    map<ll, ll> freq;
    
    ll sum = 0;
    for (auto &x : s) {
        cin >> x;
        freq[x]++;
        sum += x;
    }

    vector<pair<ll, ll>> gr;
    vector<ll> odd;
    for(auto [key, val] : freq){
        gr.push_back({key, val});
        if(val%2) odd.push_back(key);
    }

    sort(rall(gr));
    sort(all(odd));

    ll sub = 0;
    if (sz(odd) > 2) for (ll i = 0; i < sz(odd) - 2; i++) sub += odd[i];
    
    ll cur = sum, remain = n, ans = 0;

    for (auto &[len, cnt] : gr) {
        ll cand = cur - sub;
        ll cost = remain - max(0, sz(odd) - 2);
        dbg(cand, cost);

        if (cost >= 3 && cand > 2 * len) {
            ans = cand;
            // dbg(ans);
            break;
        }

        cur -= len * cnt;
        remain -= cnt;
        dbg(cur, remain);

        if (cnt%2) {
            if (sz(odd) > 3) sub -= odd[sz(odd) - 3];
            else sub = 0;
            odd.pop_back();
        }
    }

    cout << ans << endl;
}

signed main(){
    fastio;
    ll cases = 1;
    cin >> cases;
    for(ll i = 0; i < cases; i++) solution();
    return 0;
}