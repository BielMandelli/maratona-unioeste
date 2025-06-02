#include <bits/stdc++.h>
using namespace std;
#define int long long


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> x(n), y(n);

        int minX = 1e18, maxX = -1e18, minY = 1e18, maxY = -1e18, minX2 = 1e18, maxX2 = -1e18, minY2 = 1e18, maxY2 = -1e18;
        map<int, int> cx, cy;
        for (int i = 0; i < n; i++) {
            cin >> x[i] >> y[i];
            cx[x[i]]++;
            cy[y[i]]++;

            if(minX > x[i]) {
                minX2 = minX;
                minX = x[i];
            }

            if(maxX < x[i]) {
                maxX2 = maxX;
                maxX = x[i];
            }

            if(minY > y[i]) {
                minY2 = minY;
                minY = y[i];
            }

            if(maxY < y[i]) {
                maxY2 = maxY;
                maxY = y[i];
            }
        }
        
        cout << maxY << " " << maxX << " "  << minY << " " << minX << endl;
        
        int best = (maxX - minX + 1) * (maxY - minY + 1);

        cout << best << endl;

        for (int i = 0; i < n; i++)
        {   
            bool border = (x[i] == maxX or x[i] == minX or y[i] == maxY or y[i] == minY);
            if(!border) continue;

            int x1,x2,y1,y2;
            if(x[i] == maxX && cx[maxX] == 1) x2 = maxX2;
            else x2 = maxX;

            if(x[i] == minX && cx[minX] == 1) x1 = minX2;
            else x1 = minX;

            if(y[i] == maxY && cx[maxY] == 1) y2 = maxY2;
            else y2 = maxY;

            if(y[i] == minY && cx[minY] == 1) y1 = minY2;
            else y1 = minY;

            best = min(best, (x2 - x1 + 1) * (y2 - y1 + 1));
        }
        
        cout << best << endl;
    }

    return 0;
}
