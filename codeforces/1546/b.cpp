#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
#define int long long
const int MOD = 1e9+7;

signed main(){
    fastio;
    int t;
    cin >> t;
    while (t--)
    {
        int n,m;
        cin >> n >> m;
        vector<char> ans(m, 0);
        string s;

        n = (n*2)-1;
        for (int i = 0; i < n; i++)
        {
            cin >> s;
            for (int j = 0; j < m; j++)
            {
                ans[j] ^= s[i];
            }
        }
        
        for (int i = 0; i < m; i++)
        {
            cout << ans[i];
        }
        cout << endl;
        
    }
    
   
    return 0;
}