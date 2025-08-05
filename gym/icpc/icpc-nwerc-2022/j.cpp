#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

struct sus{
    int l, r, id, ans;
};

bool compare(sus &x, sus &y){
    if(x.l != y.l) return x.l < y.l;
    return x.r > y.r;
}

bool compareId(sus &x, sus &y){
    return x.id < y.id;
}

void solve()
{
    int n;
    cin >> n;

    vector<sus> p(n);
    for(int i = 0; i < n; i++) {
        cin >> p[i].l >> p[i].r;
        p[i].r += p[i].l;
        p[i].id = i;
    }

    sort(p.begin(), p.end(), compare);

    map<int,int> bst = {{2e9, 0}};

    for (int i = 0; i < n; i++)
    {
        auto idx = bst.lower_bound(p[i].r);
        int prevBst = (idx != bst.end() ? idx->second : 0);
        p[i].ans = prevBst + 1;

        auto it = bst.insert_or_assign(p[i].r, p[i].ans).first;

        if (it != bst.begin()) {
            auto bef = prev(it);
            if (bef->second <= p[i].ans) {
                bst.erase(bef);
            }
        }
    }

    sort(p.begin(), p.end(), compareId);
    
    for(auto &x : p) cout << x.ans-1 << " ";
    cout << endl;
}

signed main()
{
    bieo;
    int t = 1;
    // cin >> t;

    while (t--) solve();

    return 0;
}