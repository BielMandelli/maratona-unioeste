#include <bits/stdc++.h>
using namespace std;
#define ll long long


ll series(ll r, ll m) {
    ll soma = 0;
    ll valor = r;

    for (ll i = 0; i <= m; i++) {
        soma += valor;
        if (soma > 1e18) break;
        valor *= r;
    }
    return soma;
}


int main() {
    ll n;
    cin >> n;

    vector<ll> divisores;
    for (ll i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            divisores.push_back(i);
            if (i != n / i) {
                divisores.push_back(n / i);
            }
        }
    }
    sort(divisores.begin(), divisores.end());
    ll count = 1;

    for (ll S : divisores) {
        if (S == 1) continue;

        for (ll m = 1; ; ++m) {
            ll Sminimo = llround(pow(2, m+1)-1);
            if (Sminimo > S) break;

            ll menor = 2, maior = S;
            while (menor <= maior) {
                ll meio = (menor + maior) / 2;
                ll sum = series(meio, m);

                if (sum == S) {
                    count++;
                    break;
                } else if (sum < S) {
                    menor = meio + 1;
                } else {
                    maior = meio - 1;
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}