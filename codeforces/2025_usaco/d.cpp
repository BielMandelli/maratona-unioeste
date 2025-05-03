#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long

signed main()
{
    bieo;
    int t;
    cin >> t;

    while(t--){
        int n,k,q;
        cin >> n >> k >> q;
        vector<int> a(n);
        for(auto &x : a) cin >> x;

        int totalDist = 0, dist;
        multiset<int> distances;

        for (int i = 1; i < n; i++) {
            dist = a[i] - a[i-1] - 1;
            totalDist += dist;
            distances.insert(dist);
        }

        int index, value;
        for (int i = 0; i < q; i++)
        {
            cin >> index >> value;
            index--;

            if(index > 0){
                dist = a[index] - a[index-1] - 1;
                totalDist -= dist;
                auto it = distances.find(dist);
                distances.erase(it);
            }

            if(index < n-1){
                dist = a[index+1] - a[index] - 1;
                totalDist -= dist;
                auto it = distances.find(dist);
                distances.erase(it);
            }

            a[index] = value;

            if(index > 0){
                dist = a[index] - a[index-1] - 1;
                totalDist += dist;
                distances.insert(dist);
            }

            if(index < n-1){
                dist = a[index+1] - a[index] - 1;
                totalDist += dist;
                distances.insert(dist);
            }

            if(totalDist >= k && *distances.begin() >= 0) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
    
    return 0;
}