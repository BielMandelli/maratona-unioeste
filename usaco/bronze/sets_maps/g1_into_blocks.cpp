#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
#define int long long
const int MOD = 1e9 + 7;

signed main()
{
    fastio;
    int n,q;
    cin >> n >> q;
    vector<int> a(n);
    
    map<int, int> end, freq;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        end[a[i]] = i;
        freq[a[i]]++;
    }

    map<int, bool> seen;

    int l = -1, r = -1, t = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
        if(!seen[a[i]]){
            seen[a[i]] = true;
            if(l == -1){
                l = i;
                r = end[a[i]];
                t = freq[a[i]];
            } else {
                t = max(t, freq[a[i]]);
                r = max(r, end[a[i]]);
            }
        }

        if(i == r){
            ans += (r - t - l + 1);
            l = r = -1;
        }
    }

    cout << ans << endl;
    
    return 0;
}