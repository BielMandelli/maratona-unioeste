#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bieo cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

signed main()
{
    bieo;

    int t;
    cin >> t;

    while (t--)
    {   
        int n, m;
        cin >> n >> m;

        vector<vector<int>> gcols(m), grows(n), start(n, vector<int>(m)), goal(n, vector<int>(m));

        map<int, int> colStart;
        map<int, int> rowStart;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                cin >> start[i][j];
                colStart[start[i][j]] = j;
                rowStart[start[i][j]] = i;
            }

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                cin >> goal[i][j];
                grows[i].push_back(goal[i][j]);
                gcols[j].push_back(goal[i][j]);
            }

        bool valid = true;
        for (int i = 0; i < n; i++)
        {
            int cur;
            for (int j = 0; j < grows[i].size(); j++)
            {
                if (!j) cur = rowStart[grows[i][j]];
                else if (rowStart[grows[i][j]] != cur)
                {
                    valid = false;
                    break;
                }
            }
        }

        if (valid)
        {
            for (int i = 0; i < m; i++)
            {
                int cur;
                for (int j = 0; j < gcols[i].size(); j++)
                {
                    if (!j) cur = colStart[gcols[i][j]];
                    else if (colStart[gcols[i][j]] != cur)
                    {
                        valid = false;
                        break;
                    }
                }
            }
        }

        cout << ((valid) ? "YES" : "NO") << endl;
    }

    return 0;
}
