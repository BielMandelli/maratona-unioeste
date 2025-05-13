#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bieo cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

signed main() {
    bieo;
    int n, k;
    cin >> n >> k;

    int x1,x2,y1,y2;

    vector<vector<int>> b(1001, vector<int>(1001, 0));
    for (int i = 0; i < n; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        b[x1][y1]++;
        b[x1][y2]--;
        b[x2][y1]--;
        b[x2][y2]++;    
    }

    int ans = 0;
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            if(j > 0) b[i][j] += b[i][j-1];
            if(i > 0) b[i][j] += b[i-1][j];
            if(i > 0 && j > 0) b[i][j] -= b[i-1][j-1];
            ans += (b[i][j] == k);
        }
    }
    
    cout << ans << endl;

    return 0;
}
