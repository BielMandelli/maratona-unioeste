#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
#define int long long
const int MOD = 1e9 + 7;

signed main()
{
    fastio;

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> perm(n + 1);
        for (int i = 1; i <= n; i++) cin >> perm[i];

        int ans = 0, maxx = 0;
        for(int i = 1; i <= n; i++){
            maxx = max(maxx,perm[i]);
            if(maxx == i) ans++;
        }

        cout << ans << endl;
    }

    return 0;
}