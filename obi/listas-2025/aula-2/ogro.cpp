#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int x;
    cin >> x;

    bool maoEsq = true;
    for (int i = 0; i < x; i++){
        if(i == 5) cout << endl;
        cout << "I";
    }
    
    if(x == 0) cout << "*" << endl << "*" << endl;
    else if(x < 6) cout << endl << "*" << endl;

    return 0;
}