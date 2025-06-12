#include <bits/stdc++.h>
using namespace std;
#define beeu cin.tie(0)->sync_with_stdio(0)
#define int long long
const int MOD = 1e9+7;

signed main(){
    beeu;

    int n;
    string s;
    cin >> n >> s;
    vector<int> ans;
    for(int i = 1; i <= n-1; i++){
        int l = 0;
        for(int j = 0; j+i < n; j++){
            if(s[j] == s[j+i]) break;
            // cout << "1l " << s[j] << "2l" << s[j+i] << endl;
            l++;
        }
        if(l+i <= n) ans.push_back(l);
    }

    for(auto x : ans) cout << x << endl;

    return 0;
} 
