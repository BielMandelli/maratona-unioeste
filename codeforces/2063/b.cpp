#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t;
    cin >> t;
    
    while(t--){
        int n,l,r;
        cin >> n >> l >> r;
        vector<int> seq(n);
        vector<int> seqR(n);

        for (auto &x : seq) cin >> x;

        for (int i = 0; i < n; i++)
        {
            seqR[i] = seq[n-1-i];
        }

        int sumA = 0, sumB = 0, least = n+1;
        for (int i = l-1; i < r; i++)
        {
            sumA += seq[i];
            sumB += seqR[i];
        }

        int ans = min(sumA, sumB);

        if(n%2 == 0 && n > 2) ans -= 1;
        
        cout << ans << endl;
    }
    
    return 0;
}