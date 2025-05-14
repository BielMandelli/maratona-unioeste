#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bieo cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

signed main() {
    // bieo;
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> s(n);
        for(auto &x : s) cin >> x;

        int mex = -1;
        for (int i = 0; i < n; i++)
        {
            if(i == 0 && s[i] != 0){
                mex = 0;
                break;
            }
            if(i > 0 && s[i] != s[i-1]+1) {
                mex = s[i-1]+1;
                break;
            }
        }
        
        if(mex == -1) mex = s[n-1]+1;
        cout << mex << endl;
        int alice;
        cin >> alice;
        while (alice != -1)
        {
            cout << alice << endl;
            cin >> alice;
        }
        
    }
    
        
    return 0;
}
