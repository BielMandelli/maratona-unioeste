#include <bits/stdc++.h>
using namespace std;
#define beeu cin.tie(0)->sync_with_stdio(0)
#define int long long
const int MOD = 1e9 + 7;

signed main()
{
    beeu;
    int n;
    int t, mn = 1e9;
    cin >> n >> t;
    vector<int> k(n);

    for (int i = 0; i < n; i++)
    {
        cin >> k[i];
        mn = min(mn, k[i]);
    }

    int l = 0;
    int r = mn * t;
    int ans = 0;

    while (l <= r)
    {
        int mid = (l + r) / 2;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += (mid / k[i]);
            if (sum >= t)
            {
                break;
            }
        }
        if (sum >= t)
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    cout << ans << endl;
}