#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n;

    cin >> n;
    int matriz[n][n], somaLinha[n] = {}, somaColuna[n] = {}, somaMax = 0, res = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matriz[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            somaLinha[i] += matriz[i][j];
            somaColuna[i] += matriz[j][i];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            somaMax = somaColuna[j] + somaLinha[i] - matriz[i][j]*2;
            res = max(somaMax, res);
        }
    }

    cout << res << endl;
    return 0;
}
