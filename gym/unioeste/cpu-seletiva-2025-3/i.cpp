#include <bits/stdc++.h>
using namespace std;
#define beeu cin.tie(0)->sync_with_stdio(0)
#define int long long
const int MOD = 1e9+7;

signed main(){
    beeu;
    int n;
    cin >> n;

    string s;

    cin >> s;

    vector<int> nums;
    int cnt = 1;
    for (int i = 0; i < n; i++){
        if(s[i] == s[i+1]) cnt++;
        else {
            nums.push_back(cnt);
            cnt = 1;
        }
    }
    
    int ans = 0;
    for (int i = 0; i < nums.size()-1; i++){
        if(nums[i] == nums[i+1]) ans = max(ans, nums[i] + nums[i+1]);
        if(nums[i] > nums[i+1] or nums[i] < nums[i+1]) ans = max(ans, min(nums[i], nums[i+1])*2);
        if(i+2 < nums.size() && nums[i] + nums[i+2] == nums[i+1]) ans = max(ans, nums[i] + nums[i+1] + nums[i+2]);
        if(i+2 < nums.size() && nums[i] + nums[i+2] > nums[i+1]) ans = max(ans, nums[i+1]*2);
    }

    cout << ans << endl;

    return 0;

} 
