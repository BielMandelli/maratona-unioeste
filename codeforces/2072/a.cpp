#include <bits/stdc++.h>
#define int long long
using namespace std;
 
signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n, k, p, ans = 0;
        cin >> n >> k >> p;

        if(k == 0) cout << ans << endl;
        else {
            if(p*n < abs(k)) cout << "-1" << endl;
            else {
                int aux = 0;
                while (aux < abs(k)) {
                    aux += p;
                    if(aux > abs(k)) break;
                    ans++;
                }

                if(aux == abs(k)) cout << ans << endl;
                else cout << ans+1 << endl;
            }
        }
    }

    return 0;
}