#include <bits/stdc++.h>
using namespace std;
#define int long long
 
signed main(){
    string s, sub;
    cin >> s >> sub;
    int tam = sub.size(), tamO;
    
    string newString;

    for (char c : s) {
        newString += c; 
        tamO = newString.size();
        if(tamO > tam && newString.substr(tamO - tam) == sub) 
            newString.resize(tamO - tam);
    }
    
    cout << newString << endl;

    return 0;
}