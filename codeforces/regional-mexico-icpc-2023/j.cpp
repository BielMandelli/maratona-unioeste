#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
#define int long long
const int MOD = 1e9+7;

signed main(){
    fastio;

    int n, q;
    cin >> n >> q;
    vector<int> psum, psumpow;

    psum.push_back(0);
    psumpow.push_back(0);

    int aux;
    for (int i = 0; i < n; i++)
    {
        cin >> aux;
        psum.push_back(psum.back()+aux % MOD);
        psumpow.push_back(psumpow.back()+aux*aux % MOD);
    }

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--;
        int sum = (psum[r] - psum[l] + MOD) % MOD;
        int powsum = (psumpow[r] - psumpow[l] + MOD) % MOD;
        cout << (((sum * sum % MOD - powsum + MOD) % MOD) * ((MOD+1)/2)) % MOD << endl;
    }
}