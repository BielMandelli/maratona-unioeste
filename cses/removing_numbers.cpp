#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 1e9 + 7;
vector<int> dp(1e6 + 1, INT32_MAX);
int n;

signed main() {
    cin >> n;

    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        int aux = i;

        while (aux)
        {
            int digit = aux % 10;
            dp[i] = min(dp[i], 1 + dp[i - digit]);
            aux /= 10;
        }
    }

    cout << dp[n] << endl;
    
    return 0;
}
