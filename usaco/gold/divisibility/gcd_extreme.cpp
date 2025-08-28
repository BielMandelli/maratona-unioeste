#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define ll long long
#define endl '\n'

vector<ll> phi(1e6+1);
unordered_map<int, ll> memo;

void precalc() {
	for (int i = 1; i < 1e6+1; i++) { phi[i] = i; }
	for (int i = 2; i < 1e6+1; i++) {
		if (phi[i] == i) {
            phi[i]--;
			for (int j = i+i; j < 1e6+1; j += i) { phi[j] = phi[j] / i * (i-1); }
		}
	}
}

ll calc(ll n){
    if(n <= 1e6) return phi[n];
    if(memo.count(n)) return memo[n];

    ll d = sqrt(n);
    ll ans = 1LL * n * (n+1) / 2;
    for(int i = 2; n/i > d; i++) ans -= calc(n/i);
    for(int i = d; i >= 1; i--) ans -= 1LL * (n/i-n/(i+1)) * calc(i);
    memo[n] = ans;

    return ans;
}

void solve(){
    int n;
    while(cin >> n){
        if(n == 0) break;

        ll ans = 0;
        for(int i = 1; i <= n; i++) ans += i * (calc(n/i) - 1);

        cout << ans << endl;
    }
}

signed main()
{
    bieo;
    int t=1;

    precalc();

    for(int i = 2; i <= 1e6; i++) phi[i] += phi[i-1];
    
    while (t--) solve();
    
    return 0;
}