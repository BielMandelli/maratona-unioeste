#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, w;
const int MAXX = INT32_MAX;
vector<int> b;
vector<int> v;
vector<vector<int>> dp;

int solve(int items, int remain){
    if(remain < 0) return -MAXX;
    if (remain == 0 or items == 0) return 0;

    if(dp[items][remain] != 0) return dp[items][remain];

    int take = v[items] + solve(items - 1, remain - b[items]);
    int not_take = solve(items - 1, remain);

    dp[items][remain] = max(take, not_take);
    
    return dp[items][remain];
}

signed main(){
    cin >> n >> w;

    b.resize(n+1);
    v.resize(n+1);
    dp.resize(n+1, vector<int>(w+1));

    for (int i = 1; i <= n; i++)
    {
        cin >> b[i] >> v[i];
    }
    
    
    cout << solve(n,w) << endl;

    return 0;
}