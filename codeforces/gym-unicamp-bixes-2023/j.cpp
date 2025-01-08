#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll n;
    cin >> n;

    vector<ll> bts(3);
    for (ll &x : bts) cin >> x;

    vector<ll> visited(3, -1);
    ll cur = 0, rep = 0;
    while (visited[cur] == -1) {
        visited[cur] = rep++;
        cur = bts[cur];
    }

    ll cycle_start = visited[cur];
    ll cycle_length = rep - cycle_start;

    cout << rep << endl;

    if (n < rep) {
        cur = 0;
        for (ll i = 0; i < n; ++i) cur = bts[cur];
        cout << cur << endl;
    } else {
        n = (n - cycle_start) % cycle_length + cycle_start;
        cur = 0;
        for (ll i = 0; i < n; ++i) cur = bts[cur];
        cout << cur << endl;
    }

    return 0;
}
