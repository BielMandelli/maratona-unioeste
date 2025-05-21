#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long

signed main()
{
    bieo;

    int n;
    cin >> n;

    vector<vector<int>> matriz(n, vector<int>(n));
    vector<int> sumL(n), sumC(n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++){
            cin >> matriz[i][j];
            sumL[i] += matriz[i][j];
            sumC[j] += matriz[i][j];
        }
    
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++){
            if(sumL[i] < sumC[j]) ans++;
        }
            
    cout << ans << endl;
    
    return 0;
}