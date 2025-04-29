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
        vector<int> p(n), ans;

        for(auto &x : p) cin >> x;

        int r = 0;
        for (int i = 0; i < n; i++)
            if(p[min(n-1, r+1)] <= p[min(n-1, i+1)]) r = i;
        
        for (int i = r+1; i < n; i++) ans.push_back(p[i]);
        ans.push_back(p[r]);

        for (int i = r-1; i >= 0; i--)
        {
            if(p[i] > p[0]) ans.push_back(p[i]);
            else{
                for (int j = 0; j <= i; j++) ans.push_back(p[j]);
                break;
            }
        }
        
        for(auto x : ans) cout << x << " ";
        cout << endl;
    }
    
    return 0;
}
