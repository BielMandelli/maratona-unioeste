    #include <bits/stdc++.h>
    #define int long long
    const int MAXX = 1e17;
    using namespace std;

    signed main (){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int t;
        cin >> t;

        while (t--)
        {
            int n,m;
            cin >> n >> m;
            vector<vector<int>> a(n, vector<int>(m));
            vector<pair<int,int>> li(n, {0, 0});

            for (int i = 0; i < n; i++){
                li[i].second = i;
                for (int j = 0; j < m; j++){
                    cin >> a[i][j];
                    li[i].first += a[i][j];
                }
            }
                    
            sort(li.begin(), li.end());
            
            int ans = 0, cur = 0;
            for (int i = n-1; i >= 0; i--)
            {
                int ip = li[i].second;
                for (int j = 0; j < m; j++)
                {
                    cur+= a[ip][j];
                    ans+= cur;
                }
            }
                
            cout << ans << endl;
            
        }

        return 0;
    }