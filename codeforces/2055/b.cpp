#include <bits/stdc++.h>
#define int long long
using namespace std;
#define MOD = 1e9 + 7;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    
    while(t--){
        int n, diff = 0, holder;
        cin >> n;
        vector<int> original(n);
        vector<int> final(n);

        for(auto &x: original) cin >> x;
        for(auto &x: final) cin >> x;

        for (int i = 0; i < n; i++)
        {
            if(original[i] < final[i]){
                if(final[i] - original[i] > diff){
                    diff = final[i] - original[i];
                    holder = i;
                };
            }
        }

        bool isTrue = true;

        for (int i = 0; i < n; i++)
        {
            if(i == holder) continue;
            if(original[i] - diff < final[i]) isTrue = false;
        }
        
        
        if(isTrue) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}