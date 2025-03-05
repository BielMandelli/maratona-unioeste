#include <bits/stdc++.h>
using namespace std;
#define int long long
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> p(n, vector<int>(n, 0));

    int paint = 1;
    for(int i = 0; i < (n+1)/2; i++){
        for(int j = i; j < n-i; j++){
            p[i][j] = paint;
            p[j][i] = paint;
            p[n-1-i][j] = paint;
            p[j][n-1-i] = paint;
        }
        paint++;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) cout << p[i][j] << " ";
        cout << endl;
    }
        

    return 0;
}