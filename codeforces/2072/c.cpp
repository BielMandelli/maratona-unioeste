#include <bits/stdc++.h>
using namespace std;
#define int long long

unsigned int getMaxBit(unsigned int m) {
    if (m <= 1) return 0;
    int p = 31 - __builtin_clz(m - 1);
    int shift = (m == (1u << p)) ? p : p + 1;
    return (1u << shift) - 1;
}

void solve() {
    int n;
    unsigned int x;
    cin >> n >> x;

    int best_m = 0;
    for (int m = 0; m <= n; m++) {
        int base = getMaxBit(m);
        if ((base & ~x) == 0 && m + (base != x) <= n) best_m = m;
    }

    vector<int> ans(best_m);
    iota(ans.begin(), ans.end(), 0);

    int base = getMaxBit(best_m);
    if (base != x) ans.push_back(x & ~base);

    ans.resize(n, best_m > 0 ? 0u : x);

    for (auto num : ans) cout << num << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
