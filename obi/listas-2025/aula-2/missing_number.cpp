#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n;
    cin >> n;

    int somaTotal = 0, somaAtual = 0;
    for (int i = 0; i < n-1; i++)
    {
        int x;
        cin >> x;

        somaAtual += x;
    }
    
    for (int i = 1; i <= n; i++) somaTotal += i;
    
    int ans = somaTotal - somaAtual;
    
    cout << ans << endl;
    
    return 0;
}