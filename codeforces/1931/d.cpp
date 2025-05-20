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
        int n, x, y;
        cin >> n >> x >> y;

        vector<int> a(n);

        for (auto &x : a) cin >> x;
        map<pair<int,int>, int> psum;

        int curx, cury, ans = 0;
        for (int i = 0; i < n; i++)
        {   
            curx = a[i]%x;
            cury = a[i]%y;
            ans += psum[{(x-curx)%x, cury}];
            psum[{curx, cury}]++;
        }

        cout << ans << endl;
        
    }

    return 0;
}