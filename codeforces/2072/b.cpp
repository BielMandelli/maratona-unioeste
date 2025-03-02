#include <bits/stdc++.h>
#define int long long
using namespace std;
 
signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n;
        string s;
        cin >> n;
        cin >> s;

        int li = 0, tr = 0;
        for (char c : s) {
            if (c == '-') tr++;
            else li++;
        }

        int ans = 0;

        if(!li or !tr) cout << ans << endl;
        else {
            if(tr%2){
                ans = ((tr/2) * li) * ((tr/2) +1);
                cout << ans << endl;
            }
            else {
                ans = ((tr/2) * li) * (tr/2); 
                cout << ans << endl;
            }
        }
        
    }

    return 0;
}