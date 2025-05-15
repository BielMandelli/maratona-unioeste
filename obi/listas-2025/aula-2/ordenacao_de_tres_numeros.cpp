#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    int menor = min(a, min(b,c));
    int maior = max(a, max(b,c));
    int meio = a + b + c - menor - maior;

    cout << menor << endl;
    cout << meio << endl;
    cout << maior << endl;

    return 0;
}