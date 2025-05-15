#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll n, m, conj = 0;

    cin >> n >> m;

    ll matriz[n][m];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matriz[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        ll um = 0, zero = 0;
        for (int j = 0; j < m; ++j) {
            ll linha = matriz[i][j];

            if (linha == 1) um++;
            else zero++;

        }
        conj += (pow(2, um) - 1) + (pow(2, zero) - 1);
    }

    for (int i = 0; i < m; ++i) {
        ll um = 0, zero = 0;
        for (int j = 0; j < n; ++j) {
            ll coluna = matriz[j][i];

            if (coluna == 1) um++;
            else zero++;

        }
        conj += (pow(2, um) - 1) + (pow(2, zero) - 1);
    }

    conj -= n*m;
    cout << conj << endl;

    return 0;
}