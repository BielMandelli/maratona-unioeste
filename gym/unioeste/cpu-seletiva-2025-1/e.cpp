#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x : a) cin >> x;

    sort(a.begin(), a.end());

    int minn, ans = 0;
    for (int i = 0; i < n; i++)
    {
        if(!i) minn = a[i];
        else ans += a[i] - minn;
    }

    cout << ans << endl;
    
    return 0;
}
