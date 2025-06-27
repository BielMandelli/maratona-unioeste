#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t = 0, d = 0;
    cin >> t;
    for(int i = 1; i <= t; i++){
        int a = 0, x = 0, y = 0;
        cin >> a >> x >> y;
        if( (x<=a && a<=y) || (y<=a && a<=x)){
            cout << "NO" <<endl;
        }
        else cout << "YES" <<endl;
          
    }
    
    return 0;
}