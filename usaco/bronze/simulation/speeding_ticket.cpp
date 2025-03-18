#include <bits/stdc++.h>
using namespace std;
#define int long long
 
signed main(){
    int n,m,ans = 0;

    cin >> n >> m;
    vector<pair<int, int>> seg(n);
    vector<pair<int, int>> spd(m);

    for (int i = 0; i < n; i++)
    {
        cin >> seg[i].first >> seg[i].second;
    }

    for (int i = 0; i < m; i++)
    {
        cin >> spd[i].first >> spd[i].second;
    }
    

    int dist = 0, dist2 = 0;
    for (int i = 1, k = 0, j = 0; i <= 100; i++)
    {
        if(i > seg[k].first + dist) {
            dist += seg[k].first;
            k++;
        }

        if(i > spd[j].first + dist2){
            dist2 += spd[j].first;
            j++;
        } 

        if(spd[j].second - seg[k].second > 0) ans = max(ans, spd[j].second - seg[k].second);
    }
    
    cout << ans << endl;

    return 0;
}