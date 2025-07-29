#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll t;

    cin >> t;

    while(t--){
        ll n, u;
        cin >> n >> u;
        vector<ll> diff(n+2);

        ll l, r, val;
        for (int i = 0; i < u; i++) {
            cin >> l >> r >> val;
            diff[l] += val;
            diff[r+1] -= val;
        }

        vector<ll> psum(n+1);
        psum[0] = diff[0];
        for (int i = 1; i <= n; ++i) {
            psum[i] = psum[i-1] + diff[i];
        }

        ll q, query;
        cin >> q;
        for (int i = 0; i < q; i++) {
            cin >> query;
            cout << psum[query] << endl;
        }
    }

    return 0;
}
