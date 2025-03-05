#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> p(5);
    for (auto &x : p) cin >> x;

    int t = 1, pl = 0, sts = 0;
    sort(p.begin(), p.end(), greater<int>());

    for (int i = 0; i < 4; i++)
    {
        if(sts == 2) break;
        if(p[i] == p[i+1]) {
            if(!sts) t++;
            else pl++;
        }
        else {
            if(!t && !sts) t++;
            else if(!pl && sts) pl++;
            sts++;
            if(sts == 1) pl++;
        }
    }

    cout << t << " " << pl << endl;
    
    return 0;
}