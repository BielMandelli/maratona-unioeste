#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define bieo cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

signed main()
{
    bieo;
    int t;
    cin >> t;

    vector<vector<int>> factors(1e5 + 1);
    for (int i = 1; i <= 1e5; i++)
        for (int j = i; j <= 1e5; j += i)
            factors[j].push_back(i);

    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> s(n);
        vector<int> freq(1e5 + 1);
        for (auto &x : s)
            cin >> x;

        sort(s.begin(), s.end());

        int tc = 0, ans = 1e13;
        int l = 0, r = 0;
        while (l < n)
        {
            while (r < n && tc < m)
            {
                for (auto x : factors[s[r]])
                {
                    if (x <= m)
                    {
                        freq[x]++;
                        if (freq[x] == 1) tc+=1;
                    }
                }

                r++;
            }

            if (tc == m) ans = min(ans, s[r - 1] - s[l]);

            for(auto x : factors[s[l]]){
                if (x <= m)
                {
                    freq[x]--;
                    if (freq[x] == 0) tc-=1;
                }
            }

            l++;
        }

        cout << ((ans == 1e13) ? -1 : ans) << endl;
    }

    return 0;
}
