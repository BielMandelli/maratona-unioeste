#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bieo cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

signed main() {
    bieo;
    int n,k;
    cin >> n >> k;

    vector<int> a(n+1);

    int l,r;
    for (int i = 0; i < k; i++)
    {
        cin >> l >> r;
		l--; r--;
		a[l]++;
		a[r+1]--;
    }

    vector<int> psum(n);
    int cur = 0;
    for (int i = 0; i < n; i++)
    {
        cur += a[i];
        psum[i] = cur;
    }
    
    sort(psum.begin(), psum.end());
    cout << psum[n/2] << endl;
    
    return 0;
}
