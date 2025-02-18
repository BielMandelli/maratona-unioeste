#include <bits/stdc++.h>
#define int long long
using namespace std;
 
signed main(){
    int t;
    cin >> t;

    while(t--){
        int n, ans = 0;
        cin >> n;
        vector<int> a(n);
        vector<int> freq1;
        vector<int> freq2;
        vector<int> freq3;

        for (int i = 0; i < n; i++){
            cin >> a[i];
            if(a[i] == 1) freq1.push_back(i);
            else if(a[i] == 2) freq2.push_back(i);
            else if(a[i] == 3) freq3.push_back(i);
        }

        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());
        sort(freq3.begin(), freq3.end());

        int l, r;
        bool tr1 = true, tr2 = true;
        for (int i = 0, j = n-1; i < n; i++){
            if(a[i] == 1 && tr1){
                l = i;
                tr1 = false;
            }
            if(a[j] == 3 && tr2){
                r = j;
                tr1 = false;
            }
            j--;
        }

        int j = 0, k = 0, p = 0;
        int base = 1;
        for (int i = l; i <= r; i++){
            if(freq2[freq2.size() - 1] < freq3[0]){
                int tw = freq2.size() ;
                ans += tw * freq3.size();
                break;
            }

            
        }

        cout << ans << endl;


    }

    return 0;
}