#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bieo cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

signed main()
{
    bieo;
    int n, vb, vs;
    cin >> n >> vb >> vs;

    vector<int> bus(n);
    for (auto &x : bus)
        cin >> x;

    int x, y;
    cin >> x >> y;

    int ans;
    double dist, lin, mdist = DBL_MAX, minn = DBL_MAX;
    for (int i = 1; i < n; i++)
    {
        dist = sqrt(((x - bus[i]) * (x - bus[i]) + (y * y)));
        lin = ((double) bus[i] / (double) vb) + (dist / (double) vs);
        // cout << "i " << i << " " << cur << endl;
        if (lin < minn)
        {
            minn = lin;
            mdist = dist;
            ans = i + 1;
        }
        else if ((lin-minn) < 0.0001 && dist < mdist)
        {
            minn = lin;
            mdist = dist;
            ans = i + 1;
        }
    }

    cout << ans << endl;

    return 0;
}
