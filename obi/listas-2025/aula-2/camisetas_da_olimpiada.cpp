#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n, t, p, m;
    int countP = 0, countM = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t;
        if (t == 1) countP++;
        else countM++;
    }
    cin >> p;
    cin >> m;
    if (countP >= p && countM >= m) cout << "S";
    else cout << "N";
}