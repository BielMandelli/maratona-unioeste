#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n;
    int aux, dist;
    vector<int> fita, pintura;

    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> aux;
        fita.push_back(aux);
    }

    for (int i = 0; i < n; ++i) {
        if(fita[i] == -1) {
            aux = INT_MAX;
        for (int j = 0; j < n; ++j) {
            if(i == j) continue;
            if(fita[j] == 0) {
                dist = abs(j - i);
                aux = min(dist, aux);
            }
            }
            if(aux >= 9) aux = 9;
            if(i == n) cout << aux;
            cout << aux << " ";
        }
        else {
            cout << 0 << " ";
        }
    }

    return 0;
}
