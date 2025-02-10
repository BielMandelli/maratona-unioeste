    #include <bits/stdc++.h>
    #define int long long
    const int MAXX = 1e17;
    using namespace std;

    signed main (){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int t;
        cin >> t;

        while (t--)
        {
            int maxH, m, x;
            cin >> m >> x;

            vector<int> hap(m);
            vector<int> cost(m);

            for (int i = 0; i < m; i++) cin >> cost[i] >> hap[i];
            
            maxH = accumulate(hap.begin(), hap.end(), 0);
            
            vector<int> dp(maxH+1, MAXX);
            dp[0] = 0;

            for (int i = 0; i < m; i++)
                for (int j = maxH; j > hap[i] - 1; j--)
                    if(dp[j-hap[i]] + cost[i] <= i*x) dp[j] = min(dp[j], dp[j-hap[i]]+cost[i]); 
            
            for (int i = maxH; i > -1; i--)
            {
                if(dp[i] != MAXX) {
                    cout << i << endl;
                    break;
                }
            }
        }

        return 0;
    }