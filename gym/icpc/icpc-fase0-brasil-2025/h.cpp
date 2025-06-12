#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define bieo cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

int msb(ll x) {
    int b = 0;
    while ((1 << b) <= x) b++;
    return b;
}

ll buildPalindrome(ll x) {
    int n = msb(x); 
    ll y = 0;

    for (int i = 0; i < n/2; ++i) {
        int bitPos = i;
        int mirrorPos = n - 1 - i;

        ll temp = y | (1 << bitPos) | (1 << mirrorPos);
        if (temp <= x) {
            y = temp;
        }
    }
    return y;
}

signed main() {
    bieo;

    ll x;
    cin >> x;

    if(x == 1) cout << x << endl;
    else {
        ll n = 1, i = 1;
        bool valid = false;
        while (n <= x)
        {
            if(n == x) {
                valid = true;
            n = 1 << i;
            cout << n << endl;
            i++;
        }
        
        if(valid) cout << x-1 << endl;
        else cout << buildPalindrome(x) << endl;
    }
        
    return 0;
}
