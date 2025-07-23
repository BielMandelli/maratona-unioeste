#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

struct cow {
    int c,s,d;
};

struct CompareCow {
    bool operator()(const cow& c1, const cow& c2) const {
        return c1.c > c2.c;
    }
};

void solve(){
    int n;
    cin >> n;

    int ans = 0;

    vector<cow> a;

    for (int i = 0; i < n; i++)
    {
        cow c;
        cin >> c.s >> c.d;
        c.c = i; 
        a.push_back(c);
    }

    sort(a.begin(), a.end(), [](const cow &a, const cow &b) { return a.s < b.s; });

    priority_queue<cow, vector<cow>, CompareCow> pq, w;
    int cur = 0, time = 0;

    while (cur < n or !w.empty())
    {
        if(cur < n && a[cur].s <= time){
            w.push(a[cur]);
            cur++;
        } else if (w.empty()) {
            time = a[cur].s + a[cur].d;
            cur++;
        } else {
            cow nxt = w.top();
            ans = max(ans, time - nxt.s);

            time += nxt.d;
            w.pop();
        }
    }

    cout << ans << endl;
}

signed main()
{
    bieo;
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
