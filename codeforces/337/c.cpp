#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bieo cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
int const MOD = 1e9 + 9;

int sqexp(int n){
    int sum = 1, p = 2;
    while(n){
        if(n&1) sum = sum * p % MOD;
        p = p*p%MOD;
        n >>= 1;
    }
    return sum;
}

int calc(int n, int k){
    return (n % k + (sqexp(n/k + 1) -2) * k % MOD + MOD) % MOD;
}

signed main() {
    bieo;
    int n, m, k;
    cin >> n >> m >> k;
    
    int ans = 0;
    if((n-m) * k >= n) ans = m;
    else ans = (n-m) * (k-1) + calc(n - (n - m) * k, k);

    cout << (ans+MOD) % MOD << endl;
        
    return 0;
}
