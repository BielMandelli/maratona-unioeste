#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bieo cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

double calc(int x, int y){
    int res = (x*x) + (y*y);
    return sqrt(res);
}

signed main() {
    bieo;
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<int> work, mine;

        for (int i = 0; i < n*2; i++)
        {
            int x,y;
            cin >> x >> y;
            if(!x) work.push_back(abs(y));
            else mine.push_back(abs(x));
        }

        sort(work.begin(), work.end());
        sort(mine.begin(), mine.end());
        
        double ans = 0.00;
        for (int i = 0; i < n; i++) {
            // cout << "mines " << mine[i] << " work " << work[i] << endl;
            ans += calc(mine[i], work[i]);
        }
        
        cout << setprecision(15) << fixed;
        cout << ans << endl;
    }
        
    return 0;
}
