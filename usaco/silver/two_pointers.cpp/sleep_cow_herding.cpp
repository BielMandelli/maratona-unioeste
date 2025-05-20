#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bieo cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

signed main() {
    bieo;
    int n;
    cin >> n;
    vector<int> c(n);
    for(auto &x : c) cin >> x;
    sort(c.begin(), c.end());

    int minM = 1e16;
    if(c[n-2] - c[0] == n-2 && c[n-1] - c[n-2] > 2) minM = 2;
    else if(c[n-1] - c[1] == n-2 && c[1] - c[0] > 2) minM = 2;
    else {
        int lcow = 0;
        for (int i = 0; i < n; i++)
        {
            while (lcow + 1 < n && c[lcow+1] - c[i] < n) lcow++;
            minM = min(minM, n - (lcow - i + 1));
        }
    }

    int gap = 0;
    for (int i = 1; i < n; i++) gap += c[i] - c[i-1] - 1;
    
    int maxM = max(gap - (c[1] - c[0] - 1), gap - (c[n-1] - c[n-2] - 1));
    
    cout << minM << endl << maxM << endl;
    
    return 0;
}
