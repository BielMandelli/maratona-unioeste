#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main (){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n, c1 = 0, c0 = 0, ans1, ans2;
        cin >> n;
        vector<int> lamps(2*n);

        for (int i = 0; i < 2*n; i++)
        {
            cin >> lamps[i];
            if(lamps[i]) c1++;
            else c0++;
        }

        if(c0 >= n) ans1 = 0;
        else ans1 = c1 - c0;

        ans2 = c1;

        cout << ans1 << " " << ans2 << endl;
    }
    

    return 0;
}