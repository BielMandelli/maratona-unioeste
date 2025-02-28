#include <bits/stdc++.h>
#define int long long
using namespace std;
 
signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(0);
 
    int x, y;
    cin >> x >> y;
    x += x%y;
    for (int i = 0; i < 30; i++)
    {    
        if(x%y == 0) {
            cout << "Yes" << endl;
            return 0;
        }
        x += x%y;
    }
       
    cout << "No" << endl;
 
    return 0;
}