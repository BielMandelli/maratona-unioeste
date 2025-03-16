#include <bits/stdc++.h>
using namespace std;
#define beeu cin.tie(0)->sync_with_stdio(0)
#define int long long
const int MOD = 1e9+7;

signed main(){
    beeu;

    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for(auto &x : a) cin >> x;

    vector<int> ans(n);
    iota(ans.begin(), ans.end(), 1);

    int beginn = (m > 0) ? a[0]-1 : 0;
    for (int i = 0; i < m; i++){
        int lastI = a[i];

        while(i+1 < m && a[i]+1 == a[i+1]) {
            lastI++;
            i++;
        }

        // cout << "beginn " << beginn <<  " end: " << lastI << endl;
        
        sort(ans.begin() + beginn, ans.begin() + lastI + 1, greater<int>());
    
        beginn = (i+1 < m) ? a[i+1]-1 : 0;
    }

    for(auto x : ans) cout << x << " ";
    cout << endl;

    return 0;
} 
