#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bieo cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

signed main() {
    bieo;

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        set<int> a;

        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            a.insert(x);
        }
        
        for (auto it = a.begin(); it != a.end(); ) {
            auto nxt = next(it);
            // cout << *it << " <--> " << *nxt << endl;
            if (nxt != a.end() && (*it + 1) == *nxt) {
                a.erase(nxt);
            } else it++;
            
        }
        
        cout << a.size() << endl;
    }
    
    return 0;
}
