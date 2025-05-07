#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bieo cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

signed main()
{
    bieo;
    string s;
    cin >> s;

    cout << setprecision(15) << fixed;

    vector<int> cnt(26);
    vector<vector<vector<int>>> dp(s.size(), vector<vector<int>>(26, vector<int>(26)));

    for (int i = 0; i < s.size(); i++)
    {
        int c = s[i] - 'a';
        cnt[c]++;
        for (int j = 0; j < s.size(); j++)
        {
            int d = s[(i + j) % (int) s.size()] - 'a';
            dp[j][c][d]++;
        }
    }

    double prob = 0, sum = 0, maxx;
    int x, y;

    for (int i = 0; i < 26; i++)
    {
        maxx = 0;
        for (int j = 0; j < s.size(); j++)
        {      
            x = y = 0;
            for (int k = 0; k < 26; k++)
            {
                if(dp[j][i][k]==1) x++;
                y += dp[j][i][k];
            }
            prob = (double) x/y;
            if(prob>maxx) maxx = prob;
        }
        sum += maxx*cnt[i];
    }

    double ans = sum /= s.size();
    cout << ans << endl;

    return 0;
}
