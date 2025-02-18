#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
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