#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

bool comp(const string &a, const string &b) {
    if (a.size() != b.size())
        return a.size() > b.size();
    return a > b;
}

void solve() {
    string s;
    cin >> s;
    int n = s.size();

    if (s.find('0') == string::npos) {
        cout << "1 " << n << " 1 1" << endl;
        return;
    }

    int f0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            f0 = i;
            break;
        }
    }

    int len = n - f0;
    string bestXor = "";
    int l2 = 1;

    for (int i = 0; i + len <= n; i++) {
        string sub = s.substr(i, len);
        string curStr = "";

        for (int j = 0; j < len; j++) curStr += (s[f0 + j] != sub[j]) ? '1' : '0';

        if (comp(curStr, bestXor)) {
            bestXor = curStr;
            l2 = i + 1;
        }
    }

    cout << "1 " << n << " " << l2 << " " << (l2 + len - 1) << endl;
}

signed main() {
    bieo;
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
