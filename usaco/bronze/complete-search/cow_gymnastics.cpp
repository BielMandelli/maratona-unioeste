#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
#define int long long
const int MOD = 1e9 + 7;

signed main()
{
    fastio;

    int n, k;
    cin >> k >> n;
    vector<vector<int>> g(k, vector<int>(n));
    int aux;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> g[i][j];
        }
    }

    set<pair<int,int>> f;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i == 0){
                for (int l = j+1; l < n; l++)
                {
                    f.insert({g[i][j], g[i][l]});
                }
            } else{
                for (int l = j+1; l < n; l++)
                {
                        if(f.count({g[i][j], g[i][l]}) > 0) continue;
                        else {
                            if(f.count({g[i][l], g[i][j]}) > 0) f.erase({g[i][l], g[i][j]});
                        }
                }
            }
        }
    }
    
    cout << f.size() << endl;
    

    return 0;
}