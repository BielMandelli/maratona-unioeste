#include <bits/stdc++.h>
using namespace std;

#define int long long
#define bieo cin.tie(0)->sync_with_stdio(0)

bool check(int x) {
    string s = to_string(x);
    return s.front() == '7' || s.back() == '7';
}

signed main() {
    bieo;
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int sum = 0;
        for (int j = i; j < n; ++j) {
            sum += a[j];
            if (check(sum)) ans++;
        }
    }

    cout << ans << '\n';
    return 0;
}
