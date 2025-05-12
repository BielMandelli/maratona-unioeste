#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bieo cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

signed main() {
    // bieo;
    int n;
    string s;
    cin >> n >> s;
    set<char> m;
    for (int i = 0; i < n; i++) m.insert(s[i]);
    
    int maxx = m.size();

    int l = 0, r = 0, ans = 1e9, cur = 0;
    multiset<char> pk;
    map<char, int> cnt;
    while (l <= r && r <= n && l < n)
    {
        
        if(cur == maxx){
            ans = min((r-l), ans);
            pk.erase(pk.begin());
            cnt[s[l]]--;
            if(!cnt[s[l]]) cur--;

            l++;
        } else if (r < n){
            pk.insert(s[r]);
            if(!cnt[s[r]]) cur++;
            cnt[s[r]]++;
            r++;
        } else {
            pk.erase(pk.begin());
            cnt[s[l]]--;
            if(!cnt[s[l]]) cur--;
            l++;
        }

        // cout << l << " " << r << " cur" << cur << endl;
    }

    cout << ans << endl;
    
    return 0;
}
