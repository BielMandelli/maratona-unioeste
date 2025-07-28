#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

const double pi = acos(-1) / 2;

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<string> lines(n);
    for (int i = 0; i < n; i++) cin >> lines[i];
    
    vector<vector<double>> grid(1410, vector<double>(1410));
    for (int i = 0; i <= 2*n; i++)
    {
        for (int j = 0; j <= 2*m; j++)
        {
            grid[i][j] = -1e9;
        }
    }
    
    priority_queue<pair<double, pair<int,int>>> pq;
    pq.push({-1, {0,1}});
    pq.push({-1, {1,0}});

    while (!pq.empty())
    {
        auto [d, p] = pq.top();
        auto [i, j] = p;
        pq.pop();
        if(d < grid[i][j]) continue;
        if(i+j == 2 * n + 2 * m - 1){
            cout << setprecision(10) << fixed;
            cout << 5 * (-d+1) << endl;
            return;
        }

        if(i+1 <= 2*n && j+1 <= 2*m){
            double e = d - (lines[i/2][j/2] == 'O' ? pi : 2);
            if(grid[i+1][j+1] < e){
                grid[i+1][j+1] = e;
                pq.push({e, {i+1, j+1}});
            }
        }

        if(i%2){
            if(i+2 <= 2*n){
                if(grid[i+2][j] < d-2){
                    grid[i+2][j] = d-2;
                    pq.push({d-2, {i+2, j}});
                }
            }
        } else {
            if(j+2 <= 2*m){
                if(grid[i][j+2] < d-2){
                    grid[i][j+2] = d-2;
                    pq.push({d-2, {i, j+2}});
                }
            }
        }
    }
}

signed main()
{
    bieo;
    int t = 1;
    // cin >> t;

    while (t--) solve();

    return 0;
}