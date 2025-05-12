#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bieo cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

signed main() {
    bieo;
    int n,m;
    cin >> n >> m;
    vector<string> c(n);
    for(auto &x : c) cin >> x;

    string ans = "";
    for(int i = 0; i < m; i++){
        vector<int> cnt(26);
        for(int j = 0; j < n; j++){
            cnt[c[j][i]-'a']++;
        }
        char a;
        int cur = 0;
        for(int j = 0; j < 26; j++){
            if(cur < cnt[j]){
                a = 'a'+j;
                cur = cnt[j];
            }
        }

        ans += a;
    }

    cout << ans << endl;
        
    return 0;
}
