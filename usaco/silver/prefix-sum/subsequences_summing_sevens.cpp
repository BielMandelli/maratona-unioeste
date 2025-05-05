#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bieo cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

signed main() {
    bieo;
    int n;
    cin >> n;
    vector<int> psum(7, -1);
    psum[0] = 0;

    int ans = 0, cur = 0;
    for (int i = 1; i <= n; i++)
    {
        int c;
        cin >> c;

        cur = (cur + c) % 7;
        if(psum[cur] == -1) psum[cur] = i;
        else ans = max(ans, i - psum[cur]);
    }

    cout << ans << endl;
    
    return 0;
}
