#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long

signed main()
{
    bieo;
    int x,y,z;
    cin >> x >> y >> z;

    int minAns, maxAns;

    if(y-2 == x or y+2 == z) minAns = 1;
    else minAns = 2;

    maxAns = max(y - x, z - y) - 1;
    
    vector<int> v = {x, y, z};
    sort(v.begin(), v.end());

    if(v[0]+1 == v[1] && v[1]+1 == v[2]) {
        minAns = 0;
        maxAns = 0;
    }

    cout << minAns << endl << maxAns << endl;
    
    return 0;
}