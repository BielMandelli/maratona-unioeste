#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

int normalize(int lon) {
    while (lon < -360) lon += 720;
    while (lon >= 360) lon -= 720;
    return lon;
}

int to_index(int lon) {
    return (lon + 360) % 720;
}

void solve() {
    int n;
    cin >> n;
    vector<int> l(n);

    for (int i = 0; i < n; ++i) {
        int lat, lon;
        cin >> lat >> lon;
        l[i] = lon * 2;
    }

    vector<bool> visited(720, false);

    for (int i = 0; i < n; ++i) {
        int a = l[i];
        int b = l[(i + 1) % n];

        int diff = abs(a - b);
        if (diff > 360) diff = 720 - diff;

        if (diff >= 360) {
            cout << "yes" << endl;
            return;
        }

        int forward = (b - a + 720) % 720;
        int step = (forward <= 360) ? 1 : -1;

        int curr = a;
        while (true) {
            visited[to_index(curr)] = true;
            if (curr == b) break;
            curr = normalize(curr + step);
        }
    }

    for (int i = 0; i < 720; ++i) {
        if (!visited[i]) {
            double ans = -180.0 + 0.5 * i;
            cout << fixed << setprecision(1);
            cout << "no " << ans << endl;
            return;
        }
    }

    cout << "yes" << endl;
    return;
}

signed main()
{
    bieo;
    int t=1;
    // cin >> t;

    while (t--) solve();
    
    return 0;
}