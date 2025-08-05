#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define ll long long
#define ld long double
#define sz(a) ((int)(a).size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

#define DEBUG

void debug_out(string s, int line) { cerr << endl; }
template<typename H, typename... T>
void debug_out(string s, int line, H h, T... t){
    if (s[0] != ',') cerr << "Line(" << line << ") ";
    do{ cerr << s[0]; s = s.substr(1);
    } while (s.size() and s[0] != ',');
    cerr << " = " << h;
    debug_out(s, line, t...);
}

#ifdef DEBUG
#define dbg(...) debug_out(#__VA_ARGS__, __LINE__, __VA_ARGS__)
#else
#define dbg(...) 42
#endif

const ll MOD = 1e9+7;

pair<ll,int> findNumber(long long pos) {
    ll len = 1;
    ll start = 1;
    while (true) {
        ll cnt = 9LL * start;
        ll bsize = cnt * len;
        if (pos < bsize) break;
        pos -= bsize;
        start *= 10;
        len++;
    }
    ll num = start + pos / len;
    int digitIDx = pos % len;
    return {num, digitIDx};
}

ll calcAns(ll L, ll R) {
    auto [num, idx] = findNumber(L);
    ll pos = L;
    ld bestLog = -1e300L;
    ld curLog = 0.0L;

    string bestBlock;
    string curBlock;

    while (pos <= R) {
        string s = to_string(num);
        for (int i = idx; i < s.size() && pos <= R; i++) {
            char c = s[i];
            if (c == '0') {
                if (!curBlock.empty() && curLog > bestLog) {
                    bestLog = curLog;
                    bestBlock = curBlock; 
                }
                curBlock.clear();
                curLog = 0.0L;
            } else {
                int d = c - '0';
                curBlock.push_back(c);
                curLog += log((ld)d);
            }
            pos++;
        }
        num++;
        idx = 0;
    }

    if (!curBlock.empty() && curLog > bestLog) bestBlock = curBlock;
    
    if (bestBlock.empty()) return 0;

    ll ans = 1;
    for (char c : bestBlock) ans = (ans * (ll)(c - '0')) % MOD;
    
    return ans;
}

void solve(){
    ll l,r;
    cin >> l >> r;
    l--; r--;
    ll ans = calcAns(l, r);
    cout << ans << endl;
}

int main(){
    fastio;
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}