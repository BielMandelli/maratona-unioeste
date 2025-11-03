#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int test = 0; test < t; ++test) {
        int n;
        cin >> n;
        vector<long long> a(n);
        map<long long, int> freq;
        long long total_sum = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            freq[a[i]]++;
            total_sum += a[i];
        }
        vector<pair<long long, int>> groups;
        for (auto& p : freq) {
            groups.emplace_back(p.first, p.second);
        }
        sort(groups.rbegin(), groups.rend());
        vector<long long> cur_odd;
        for (auto& p : groups) {
            if (p.second % 2 == 1) {
                cur_odd.push_back(p.first);
            }
        }
        sort(cur_odd.begin(), cur_odd.end());
        int mm = cur_odd.size();
        long long small_sum = 0;
        if (mm > 2) {
            for (int i = 0; i < mm - 2; ++i) {
                small_sum += cur_odd[i];
            }
        }
        long long cur_sum = total_sum;
        int cur_n = n;
        int idx = 0;
        long long ans = 0;
        while (true) {
            long long S = cur_sum - small_sum;
            long long M = (idx < groups.size() ? groups[idx].first : 0LL);
            int removed_num = (mm > 2 ? mm - 2 : 0);
            int remaining_k = cur_n - removed_num;
            if (remaining_k >= 3 && S > 2LL * M) {
                ans = S;
                break;
            }
            if (idx >= groups.size()) {
                break;
            }
            auto [l, f] = groups[idx];
            cur_sum -= l * 1LL * f;
            cur_n -= f;
            if (f % 2 == 1) {
                if (mm > 3) {
                    small_sum -= cur_odd[mm - 3];
                } else {
                    small_sum = 0;
                }
                cur_odd.pop_back();
                mm--;
            }
            idx++;
        }
        cout << ans << '\n';
    }
    return 0;
}