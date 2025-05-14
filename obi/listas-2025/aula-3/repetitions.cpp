#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int main() {
    string s;
    ll cont = 1, contMax = 1;
    cin >> s;
 
    for (int i = 0; i < s.size(); ++i) {
        if(s[i] == s[i+1]) {
            cont++;
            continue;
        }
        
        contMax = max(contMax, cont);
        cont = 1;
    }
 
    cout << contMax << endl;
    
    return 0;

}
