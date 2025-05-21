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
        int n, m, k;
        cin >> n >> m >> k;

        vector<vector<int>> matriz(n, vector<int>(m));

        int cur = 0;
        for (int i = 0; i < n; i++)
        { 
            for (int j = 0; j < m; j++)
            {
                if(i>0 && matriz[i-1][j] == cur+1) cur = (cur+1) % k;
                matriz[i][j] = cur+1;

                cur = (cur+1) % k;
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cout << matriz[i][j] << " ";
            
            cout << endl;
        }
    }
    
    return 0;
}