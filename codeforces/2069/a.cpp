#include <bits/stdc++.h>
#define int long long
using namespace std;
 
signed main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vector<int> b(n-2);
        for (int i = 0; i < n-2; i++){
            cin >> b[i];
        }
        bool tr = true;
        for (int i = 0; i < n-3; i++){
            if(b[i] == 1 && b[i+1] == 0 && b[i+2] == 1){
                tr = false;
                break;
            }
        }

        if(tr) cout << "YES" << endl;
        else cout << "NO" << endl;

    }

    return 0;
}