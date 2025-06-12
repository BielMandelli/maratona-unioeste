#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bieo cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

signed main() {
    bieo;
    int n, m;
    cin >> n >> m;

    int nsize = 1 << n;
    vector<int> status(nsize);
    for (int i = 0; i < nsize; i++) status[i] = i;

    while (m--)
    {
        int type;
        cin >> type;
        int c1, c2, t;

        if(type == 1){
            cin >> c1 >> t;
            c2 = c1;
        } 
        else cin >> c1 >> c2 >> t;

        vector<int> curStatus = status;

        for (int i = 0; i < nsize; i++)
        {
            int cur = status[i];

            bool c1B = (((cur / (1 << c1)) % 2) == 1);
            bool c2B = (((cur / (1 << c2)) % 2) == 1);

            // cout << c1B << " " << c2B << endl;

            if(c1B && c2B) cur ^= (1 << t);
            
            curStatus[i] = cur;
        }
        
        // for(auto x : curStatus) cout << x << " ";
        // cout << endl;

        status = curStatus;
    }

    for (int i = 0; i < nsize; i++)
    {
        string r(nsize, '0');
        r[status[i]] = '1';
        cout << r << endl;
    }

    return 0;
}