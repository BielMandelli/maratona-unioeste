#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long

signed main()
{
    bieo;
    int t;
    cin >> t;

    while(t--){
        vector<int> a(3);
        for(auto &x : a) cin >> x;

        int ans = 1e9;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 1; j <= 1e4; j++)
            {
                int n = abs(j - a[i]);
                if(i) n++;

                for (int k = 0; k < 3; k++)
                {
                    if(i != k){
                        if(a[k] < j) n += abs(a[k] - j);
                        else n += min(a[k] % j, j - (a[k] % j));
                    }
                }
                ans = min(ans, n);
            }
        }

        cout << ans << endl;
    }
    
    return 0;
}