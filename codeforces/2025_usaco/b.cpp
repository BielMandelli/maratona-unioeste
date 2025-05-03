#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long

signed main()
{
    bieo;
    int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n >> k;

        vector<int> p;
        bool sts = true;
        for (int l = n, r = 1; r <= l;)
        {
            if(sts) {
                p.push_back(l);
                l--;
            } else {
                p.push_back(r);
                r++;
            }

            sts = !sts;
        }
            
        for(auto x : p) cout << x << " ";
        cout << endl;
    }
    
    return 0;
}