#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bieo cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

signed main()
{
    bieo;

    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        int c1 = 0, c0 = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')c0++;
            else c1++;
        }

        int p1 = c1 / 2, p0 = c0 / 2;

        // cout << "p1 " << p1 << " p2 " << p0 << endl;
        int total = p0 + p1;

        if (total >= k && (total % 2 == k % 2) && total-min(p0,p1)*2 <= k) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}
