#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    
    int cnt = count(s.begin(), s.end(), '1');
    if (cnt <= k) {
        cout << "Alice" << endl;
        return;
    }
    
    if (k*2 <= n) {
        cout << "Bob" << endl;
        return;
    }
    
    cout << "Alice" << endl;
}


signed main()
{
    bieo;
    int t=1;
    cin >> t;

    while (t--) solve();
    
    return 0;
}