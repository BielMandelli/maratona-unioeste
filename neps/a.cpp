#include <bits/stdc++.h>
const int MOD = 1e9 + 7;
#define int long long
using namespace std;

signed main() {
    int n;
    bool isTrue = true;
    cin >> n;

    vector<vector<int>> m(n, vector<int>(n));

    int base;
    for (int i = 0; i < n; i++){
        base = 0;
        for (int j = 0; j < n; j++){
            cin >> m[i][j];
            base += m[i][j];
        }       
    }
        
    for (int i = 0; i < n; i++){
        int sC = 0, sL = 0;
        for (int j = 0; j < n; j++)
        {
            sL += m[i][j];
            sC += m[j][i];
        }

        if(sL != base or sC != base) isTrue = false;
    }

    int d2 = 0, d1 = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
        {
            if(i == j) d1 += m[i][j];
            if(i + j == n - 1) d2 += m[j][i];
        }
    }

    if(d1 != base or d2 != base) isTrue = false;

    if(isTrue) cout << base << endl;
    else cout << "-1" << endl;
    
    return 0; 
}