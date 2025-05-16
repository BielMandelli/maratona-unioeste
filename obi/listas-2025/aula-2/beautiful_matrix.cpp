#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int nx, ny, aux;
    
    for(int i = 1; i <=5 ; i++)
        for(int j = 1; j <=5 ; j++) {
            cin >> aux;
            if(aux) {
                nx = i;
                ny = j;
            } 
        }
    
    int ans = abs(nx - 3) + abs(ny - 3);
    cout << ans << endl;
    
    return 0;
} 