#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
#define int long long
const int MOD = 1e9 + 7;

signed main()
{
    fastio;
    int n, x;
    cin >> n >> x;
    vector<pair<int,int>> v(n);
    int c = 1;
    for(auto &x : v) {
        cin >> x.first;
        x.second = c;
        c++;
    }
    sort(v.begin(),v.end());

    int l = 0, r = n-1;
    while (l < r) { 
        int sum = v[l].first + v[r].first;
        if (sum == x) { 
            cout << v[l].second << " " << v[r].second << endl;
            return 0;
        }
        if (sum < x) l++; 
        else r--;
    }
    
    cout << "IMPOSSIBLE" << endl;
    
    return 0;
}