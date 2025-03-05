#include <bits/stdc++.h>
using namespace std;
#define int long long
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    string s, sub;
    cin >> n >> s;

    int ans = 0, initial = 0, actTam = s.size();
    while(ans < actTam)
    {
        sub = s.substr(initial, actTam);
        reverse(sub.begin(), sub.end());
        if((int)s.find(sub) >= 0) ans = sub.size();
        else if(initial + actTam == s.size()) {
            actTam--;
            initial = 0;
        }
        else initial++;
    }
    
    cout << ans << endl;

    return 0;
}