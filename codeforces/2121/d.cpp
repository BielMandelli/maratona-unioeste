#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

struct operation {
    int type, pos;
};

void solve(){
    int n; 
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;

    vector<operation> op;

    for (int i = 0; i < n; i++) {
        if (a[i] >= b[i]) {
            op.push_back({3, i+1});
            swap(a[i], b[i]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-1; j++) {
            if (a[j] >= a[j+1]) {
                op.push_back({1, j+1});
                swap(a[j], a[j+1]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-1; j++) {
            if (b[j] >= b[j+1]) {
                op.push_back({2, j+1});
                swap(b[j], b[j+1]);
            }
        }
    }

    cout << op.size() << endl;
    for (auto o : op) cout << o.type << " " << o.pos << endl;  
}

signed main()
{
    bieo;
    int t=1;
    cin >> t;

    while (t--) solve();
    
    return 0;
}