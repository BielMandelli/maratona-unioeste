#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bieo cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

signed main() {
    bieo;
    int n;
    cin >> n;

    vector<int> p(n+1), h(n+1), s(n+1);
    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        if(c == 'P') p[i+1] = p[i] + 1;
        else p[i+1] = p[i];

        if(c == 'H') h[i+1] = h[i] + 1;
        else h[i+1] = h[i];

        if(c == 'S') s[i+1] = s[i] + 1;
        else s[i+1] = s[i];
    }
    
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, p[i] + (s[n] - s[i]));
        ans = max(ans, p[i] + (h[n] - h[i]));
        ans = max(ans, s[i] + (p[n] - p[i]));
        ans = max(ans, s[i] + (h[n] - h[i]));
        ans = max(ans, h[i] + (p[n] - p[i]));
        ans = max(ans, h[i] + (s[n] - s[i]));
    }
    
    cout << ans << endl;
    
    return 0;
}
