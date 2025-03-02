#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        int bestL = 0, bestR = 0; 
        int bestDiff = 0; 
  
        for (int l = 0; l < n; l++){
            int gr = 0, less = 0;
        
            for (int r = l + 1; r < n; r++){
                if(a[r] > a[l]) gr++;
                else if(a[r] < a[l]) less++;
                    
                int diff = gr - less;
                if(diff < bestDiff){
                    bestDiff = diff;
                    bestL = l;
                    bestR = r;
                }
            }
        }
    
        cout << bestL + 1 << " " << bestR + 1 << "\n";
    }
    return 0;
}