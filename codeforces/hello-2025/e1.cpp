#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main () {
    int t;
    cin >> t;

    while(t--){
        int n,m,q;
        vector<vector<int>> edges(n, vector<int> (n, 0));
        vector<vector<int>> weights(n, vector<int> (n, 0));
        cin >> n >> m >> q;

        for (int i = 0; i < m; i++){
            for(int j = 0; j < m; i++){
                int x,y,w;
                cin >> x >> y >> w;
                edges[x][y] = 1;
                weights[x][y] = w;
            }
        }

        for (int i = 0; i < q; i++){
            int a,b,k;
            cin >> a >> b >> k;
            for(int j = 0; j < m; i++){
               
            }
        }
    }
    return 0;
}