#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bieo cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

signed main() {
    bieo;
    int n, k, q;
    cin >> n >> k >> q;

    vector<int> c(2e5+2), psum(2e5+2), valid(2e5+2);
    int l,r;
    for (int i = 0; i < n; i++)
    {
        cin >> l >> r;
        c[l]++; c[r+1]--;
    }

    for (int i = 1; i <= 2e5+2; i++) psum[i] = psum[i-1] + c[i];
    for (int i = 1; i <= 2e5+2; i++) valid[i] = valid[i-1] + (psum[i] >= k);
    
    while (q--)
    {
        cin >> l >> r;
        cout << valid[r]-valid[l-1] << endl;
    }
    
    return 0;
}
