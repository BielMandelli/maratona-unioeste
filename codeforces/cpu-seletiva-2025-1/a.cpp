#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> c(n);
    for(auto &x: c) cin >> x;

    sort(c.begin(), c.end());

    int ans = 0, gap = 0;
    for (int i = 1; i < n; i++)
    {   
        gap = max(gap, c[i] - c[i-1]);
    }

    gap = max(gap, c[0] - c[n-1] + 360);
    
    ans = 360 - (gap - 1);
    cout << ans << endl;

    return 0;
}