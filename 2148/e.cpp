#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fastio cin.tie(0)->sync_with_stdio(0)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) ((int) (a).size())
#define ld long double

void dbg_out(string s) { cerr << endl; }
template<typename H, typename... T>
void dbg_out(string s, H h, T... t){
    do { cerr << s[0]; s = s.substr(1);
    } while (sz(s) && s[0] != ',');
    cerr << " = " << h;
    dbg_out(s, t...);
}

#define int long long

#ifdef DEBUG
#define dbg(...) dbg_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 42
#endif

void solution(){
    int n, k;
    cin >> n >> k;

    vector<int> a(n), cnt(n+1);
    for(auto &x : a) {
        cin >> x;
        cnt[x] ++;
    }

    for (int i = 1; i <= n; i++)
    {
        if(cnt[i]%k) {
            cout << 0 << endl;
            return;
        } else cnt[i] /= k;
    }
    
    vector<int> sub(n+1);
    int l = 0, r = 0, ans = 0;
    while(l <= r && r < n){
        sub[a[r]]++;
        while(sub[a[r]] > cnt[a[r]]){
            sub[a[l]]--;
            l++;
        }

        ans += r - l + 1;
        r++;
    }
    cout << ans << endl;
}

signed main(){
    int cases = 1;
    cin >> cases;
    for (int i=0; i<cases; i++){
        solution();
    }
    
}