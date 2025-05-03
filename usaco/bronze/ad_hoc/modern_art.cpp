#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long

struct Rectangle {
    int y1 = 100, x1 = 100, y2 = -100, x2 = -100;
};

signed main()
{
    bieo;
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    map<int, Rectangle> mcolor;

    set<int> ans;
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++){
            char digit;
            cin >> digit;
            a[i][j] = digit - '0';

            int cur = a[i][j];
            if(cur){
                mcolor[cur].y1 = min(mcolor[cur].y1, i);
                mcolor[cur].x1 = min(mcolor[cur].x1, j);
                mcolor[cur].y2 = max(mcolor[cur].y2, i);
                mcolor[cur].x2 = max(mcolor[cur].x2, j);
                ans.insert(cur);
            }
        }

    for(auto r : mcolor){
        for (int i = r.second.y1; i <= r.second.y2; i++)
            for (int j = r.second.x1; j <= r.second.x2; j++)
                if(a[i][j] != r.first) ans.erase(a[i][j]);
    }   
    
    cout << ans.size() << endl;

    return 0;
}