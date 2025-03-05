#include <bits/stdc++.h>
#define int long long
using namespace std;
 
signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(0);

    int s, t, p;
    cin >> s >> t;
    vector<vector<bool>> m(s+1, vector<bool>(s+1, false));

    int x, y;
    for (int i = 0; i < t; i++)
    {
        cin >> x >> y;
        m[x][y] = true;
        m[y][x] = true;
    }

    cin >> p;

    int n, aux, ans = 0;
    vector<int> nums;
    for (int i = 0; i < p; i++)
    {
        cin >> n;
        nums.resize(n);
        bool valid = 1;
        for (auto &x : nums) cin >> x;
        for (int i = 0; i < n-1; i++)
        {
            if(m[nums[i]][nums[i+1]]) continue;
            else valid = 0;
        }
        ans += valid;
    }
    
    cout << ans << endl;

    return 0;
}