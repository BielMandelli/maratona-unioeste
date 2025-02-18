#include <bits/stdc++.h>
#define int long long
const int MAXX = 1e17;
using namespace std;

bool containsSeven(int n) {
    string numStr = to_string(n);
    return numStr.find('7') != string::npos;
}

int minimumOperations(int n) {
    int operations = 0;
    while (!containsSeven(n)) {
        n += 9;
        operations++;
    }
    return operations;
}

signed main (){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; 
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        if (containsSeven(n)) {
            cout << 0 << endl;
            continue;
        }

        cout << minimumOperations(n) << endl;
    }

    return 0;
}