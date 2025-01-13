#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n;
    cin >> n;

    vector<int> stones(n+1);

    for(int i = 0; i < n; i++) cin >> stones[i];

    vector<int> dp(n+1);

    dp[0] = 0;
    dp[1] = stones[0] - dp[0];

    for (int i = 1; i < n; i++)
    {
        int s1 = dp[i - 1] + abs(stones[i] - stones[i-1]);
        int s2 = dp[i - 2] + abs(stones[i] - stones[i-2]);
        
        dp[i] = min(s1,s2);
    }

    cout << dp[n-1] << endl;

    return 0;
}