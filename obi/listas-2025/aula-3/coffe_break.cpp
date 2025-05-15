#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int matrix[n][m];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
    
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            for(int k = 0; k < n; k++) {
                for(int l = 0; l < m; l++) {
                    int numCb = 0;
                    bool valid = true;
                    for(int o = i; o <= k; o++) {
                        for(int p = j; p <= l; p++) {
                            if (matrix[o][p]) numCb++;
                            else valid = false;
                        }
                    }
                    if (valid) ans = max(ans, numCb);
                }
            }
        }
    }     cout << ans << endl;
}