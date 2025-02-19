#include <bits/stdc++.h>
#define int long long
using namespace std;
 
signed main(){
    int t;  
    cin >> t;

    while(t--){
        int n, m = 0, l, intervalo = 0, start = 0;
        string s, t, sub;
        cin >> n >> s;

        l = n;

        for (int i = n-1; i >=0; i--){
            if(s[i] == '1') 
                l = i;
        }
        
        bool one;
        for (int i = n-1; i >= l; i--){
            if(s[i] == '1'){
                if(i == n-1 or start) {
                    one = true;
                    start = 0;
                }
                if(!one) intervalo++;
                one = true;
            }
            else {
                if(i == n-1) {
                    start = 1;
                    m+=1;
                }
                else if(one) one = false;
            }
        }

        if(l == n) cout << 0 << endl;
        else {
            m += (intervalo > 0) ? intervalo*2 + start +1 : 1;
            cout << m << endl;
        }
    }
    return 0;
}