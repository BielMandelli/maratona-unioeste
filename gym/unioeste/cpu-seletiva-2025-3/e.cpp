#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

vector<char> segmentedSieve(int l, int r) {
    int lim = sqrt(r);
    vector<char> mark(lim + 1, false);
    vector<int> primes;
    for (int i = 2; i <= lim; ++i) {
        if (!mark[i]) {
            primes.emplace_back(i);
            for (int j = i * i; j <= lim; j += i)
                mark[j] = true;
        }
    }

    vector<char> isPrime(r - l + 1, true);

    for (int i : primes)
        for (int j = max(i * i, (l + i - 1) / i * i); j <= r; j += i)
            isPrime[j - l] = false;

    if (l == 1) isPrime[0] = false;

    return isPrime;
}

signed main()
{
    bieo;
    int t;
    cin >> t;
    while(t--){
        int l,r;
        cin >> l >> r;
        vector<char> primes = segmentedSieve(l,r);
        for (int i = 0; i < primes.size(); i++) if(primes[i]) cout << l + i << endl;
        cout << endl;
    }
    
    return 0;
}