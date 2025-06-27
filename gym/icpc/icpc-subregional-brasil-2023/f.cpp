#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

int solve(){
    int d, c, r;
    cin >> d >> c >> r;
    queue<int> cns, rev;
    for(int i = 0; i < c; i++) {
        int x;
        cin >> x;
        cns.push(x);
    }

    for(int i = 0; i < r; i++) {
        int x;
        cin >> x;
        rev.push(x);
    }

    int cur = d, ans = 0;
    while (!rev.empty() or (!cns.empty() && cns.front() <= cur))
    {
        if(!cns.empty() && cns.front() <= cur) {
            cur -= cns.front();
            ans++;
            cns.pop();
        } else {
            cur += rev.front();
            ans++;
            rev.pop();
        }
    }
    
    return ans;
}

signed main()
{
    bieo;
    int t=1;
    // cin >> t;

    while (t--) cout << solve() << endl;
    
    return 0;
}