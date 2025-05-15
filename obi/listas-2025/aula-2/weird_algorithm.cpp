#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
    long long n;
 
    cin >> n;
    cout << n << " ";

    bool isFirst = true;
    while (n > 1)
    {
        if(n == 1 && isFirst == true) break;
    
        if(n % 2 == 0) n = n/2;
        else n = n * 3 + 1;
 
        if(n != 1) {
            cout << n << " ";
            isFirst = false;
        } else cout << 1;
    }
 
    return 0;
}
