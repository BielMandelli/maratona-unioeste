#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
#define int long long
const int MOD = 1e9 + 7;

signed main()
{
    fastio;

    int n;
    cin >> n;
    vector<int> k(n*2);
    for(auto &x : k) cin >> x;
    sort(k.begin(), k.end());

    int ans = 1e9;
    for (int i = 0; i < n*2; i++)
    {   
        for (int j = 0; j < n*2; j++)
        {   
            int cur = 0;
            vector<int> temp;

            for (int l = 0; l < n*2; l++) if(l != i && l != j) temp.push_back(k[l]);
            for (int l = 0; l < (n*2)-2; l+=2) cur += temp[l+1] - temp[l];
            
            ans = min(ans, cur);
        }
    }
    
    cout << ans << endl;
    
    return 0;
}