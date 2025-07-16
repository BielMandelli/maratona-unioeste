#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define ll long long
#define sz(a) ((int)(a).size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define ld long double

const ld LINF = 1e18;
const int MAX = 51;

int n, m; // numero de vertices
vector<pair<ld, int>> g[MAX]; // {vizinho, peso}
ll d[1 << m][MAX]; // dp[mask][v] = arvore minima com o subconjunto mask de S e o vertice v

ll steiner(const vector<int> &S) {
	int k = S.size(); // k--;
	for (int mask = 0; mask < (1 << k); mask++) for(int v = 0; v < n; v++) d[mask][v] = LINF;
	for (int v = 0; v < n; v++) d[0][v] = 0;
	for (int i = 0; i < k; ++i) d[1 << i][S[i]] = 0;
	for (int mask = 1; mask < (1 << k); mask++) {
		for (int a = (mask - 1) & mask; a; a = (a - 1) & mask) {
			int b = mask ^ a;
			if (b > a) break;
			for (int v = 0; v < n; v++)
				d[mask][v] = min(d[mask][v], d[a][v] + d[b][v]);
		}
		priority_queue<pair<ll, int>> pq;
		for (int v = 0; v < n; v++) {
			if (d[mask][v] == LINF) continue;
			pq.emplace(-d[mask][v], v);
		}
		while (pq.size()) {
			auto [ndist, u] = pq.top(); pq.pop();
			if (-ndist > d[mask][u]) continue;
			for (auto [idx, w] : g[u]) if (d[mask][idx] > d[mask][u] + w) {
				d[mask][idx] = d[mask][u] + w;
				pq.emplace(-d[mask][idx], idx);
			}
		}
	}
	return d[(1 << k) - 1][S[0]]; // S[k]
}

void solve(){
    cin >> n >> m;

    
}

signed main(){
    fastio;
    int t = 1;
    // cin >> t;
    for (int i=0; i<t; i++) solve();
}