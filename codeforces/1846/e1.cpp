#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bieo cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
vector<int> calc(1e6);

void precalc() {
    for (int i = 2; i < 1e6; i++) {
        int k = i;
        int sum = 1 + i;
        while(k * i < 1e6) {
            k *= i;
            sum += k;
            if (sum >= 1e6) break;
            calc[sum] = true;
        }
    }
}

signed main() {
    bieo;
    precalc();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        cout << ((calc[n]) ? "YES" : "NO") << endl;
    }
        
    return 0;
}
