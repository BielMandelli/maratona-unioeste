#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll n, t;
    cin >> t;

    while (t--) {
        ll count = 1;
        cin >> n;

        while (n >= 4) {
            n = n/4;
            count *= 2;
        }

        cout << count << endl;
    }

    return 0;
}
