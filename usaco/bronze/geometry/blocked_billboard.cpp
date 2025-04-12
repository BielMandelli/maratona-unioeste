#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long

signed main()
{
    bieo;
    vector<vector<int>> m(2001, vector<int>(2001, 0));

    int x1,x2,y1,y2;
    for (int i = 0; i < 2; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        x1+=1000; x2+=1000; y1+=1000; y2+=1000;
        for (int x = x1; x < x2; x++)
        {
            for (int y = y1; y < y2; y++)
            {
                m[x][y] = 1;
            }
        }
    }
    
    
    cin >> x1 >> y1 >> x2 >> y2;
    x1+=1000; x2+=1000; y1+=1000; y2+=1000;
    for (int x = x1; x < x2; x++)
        {
        for (int y = y1; y < y2; y++)
        {
            m[x][y] = 0;
        }
    }
    
    int ans = 0;
    for (int x = 0; x <= 2000; x++)
        {
        for (int y = 0; y <= 2000; y++)
        {
            ans += m[x][y];
        }
    }

    cout << ans << endl;

    return 0;
}