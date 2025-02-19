#include <bits/stdc++.h>
#define int long long
using namespace std;
 
signed main(){
    int t;  
    cin >> t;

    while (t--) {
        int n, p, pT, l, r;
        cin >> n;
        vector<int> a(n);
        vector<int> freq(n+1, 0);
        vector<int> siz(n+1, 0);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            freq[a[i]]++;
        }

        siz[0] = freq[a[0]] == 1;
        for (int i = 1; i < n; i++) {
            if(freq[a[i]] == 1) siz[i] = siz[i-1] + 1;
        }

        int maxx = *max_element(siz.begin(), siz.end());
        if(maxx == 0){
            cout << "0" << endl;
            continue;
        }

        for (int i = 0; i < n; i++) {
            if(siz[i] == maxx){
                l = i - siz[i] + 2;
                r = i + 1;
                cout << l << " " << r << endl;
                break;
            }
        }
    }
    return 0;
}