#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bieo cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

signed main() {
    bieo;

    int n;
    cin >> n;

    vector<pair<int,int>> years;

    for (int i = 0; i < n; i++)
    {
        int d,b;
        cin >> b >> d;
        years.push_back({b, 1});
        years.push_back({d,-1});
    }

    sort(years.begin(), years.end());
    
    int bestP = 0, cur = 0, bestY = 0;
    for (auto [year, pop] : years){
        cur += pop;
        if(cur > bestP){
            bestP = cur;
            bestY = year;
        }
    }

    cout << bestY << " " << bestP << endl;
        
    return 0;
}
