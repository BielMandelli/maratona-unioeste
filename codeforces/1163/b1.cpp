#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

void solve(){
    int n;
    cin >> n;
    vector<int> cnt(1e5+5), cnt2(1e5+5);
    
    int ans = 0, mx = 0;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        cnt2[cnt[x]]--;
        cnt[x]++;
        cnt2[cnt[x]]++;

        mx = max(mx, cnt[x]);

        bool valid = false;
        if(cnt2[1] == i or cnt2[i] == 1) valid = true;
        else if (cnt2[1] == 1 && cnt2[mx] * mx == i-1) valid = true;
        else if (cnt2[mx] == 1 && cnt2[mx-1] * (mx-1) == i - mx) valid = true;

        if(valid) ans = i;
    }

    cout << ans << endl;
}

signed main()
{
    bieo;
    int t=1;
    while (t--) solve();
    return 0;
}
