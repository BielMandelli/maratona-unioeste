#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bieo cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

struct cube
{
    int l, w, h;
};

signed main()
{
    bieo;
    int n, H;

    cin >> n >> H;

    int l, w, h, ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> l >> w >> h;

        vector<cube> cubes = {
            {l, w, h},
            {w, h, l},
            {l, h, w}
        };

        if (l > H && w > H && h > H)
        {
            cout << "impossible" << endl;
            return 0;
        }

        int bestL = 1e9;
        for (int i = 0; i < 3; i++){
            if(cubes[i].h <= H){
                int lg = min(cubes[i].l,cubes[i].w);
                if(lg < bestL) bestL = lg;
            }
        }

        ans += bestL;
    }

    cout << ans << endl;

    return 0;
}
