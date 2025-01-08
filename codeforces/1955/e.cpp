#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll t; 
    cin >> t;

    while (t--) {
        ll n; 
        string s; 
        cin >> n >> s;

        for (ll k = n; k > 0; --k) {
            vector<ll> flipEnds(n + 1, 0); 
            vector<ll> binary(n, 0);      
            ll activeFlips = 0;           

            for (ll i = 0; i < n; ++i) {
                binary[i] = s[i] - '0';
            }

            bool canTransform = true; 

            for (ll i = 0; i < n; ++i) {
                activeFlips -= flipEnds[i];      
                binary[i] ^= (activeFlips % 2); 

                if (binary[i] == 0) { 
                    if (i + k > n) {
                        canTransform = false;
                        break;
                    }
                    ++activeFlips;           
                    ++flipEnds[i + k];      
                }
            }

            if (canTransform) {
                cout << k << endl;
                break; 
            }
        }
    }

    return 0;
}
