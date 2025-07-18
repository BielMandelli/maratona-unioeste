#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define ll long long
#define sz(a) ((int)(a).size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define ld long double
const ld DINF = 1e18;
const ld pi = acos(-1.0);
const ld eps = 1e-9;

bool eq(ld a, ld b) {
	return abs(a - b) <= eps;
}

struct pt { // ponto
	ld x, y;
	pt(ld x_ = 0, ld y_ = 0) : x(x_), y(y_) {}
	bool operator < (const pt p) const {
		if (!eq(x, p.x)) return x < p.x;
		if (!eq(y, p.y)) return y < p.y;
		return 0;
	}
	bool operator == (const pt p) const {
		return eq(x, p.x) and eq(y, p.y);
	}
	pt operator + (const pt p) const { return pt(x+p.x, y+p.y); }
	pt operator - (const pt p) const { return pt(x-p.x, y-p.y); }
	pt operator * (const ld c) const { return pt(x*c  , y*c  ); }
	pt operator / (const ld c) const { return pt(x/c  , y/c  ); }
	ld operator * (const pt p) const { return x*p.x + y*p.y; }
	ld operator ^ (const pt p) const { return x*p.y - y*p.x; }
	friend istream& operator >> (istream& in, pt& p) {
		return in >> p.x >> p.y;
	}
};

ld dist(pt p, pt q) { // distancia
	return hypot(p.y - q.y, p.x - q.x);
}

struct line { // reta
	pt p, q;
	line() {}
	line(pt p_, pt q_) : p(p_), q(q_) {}
	friend istream& operator >> (istream& in, line& r) {
		return in >> r.p >> r.q;
	}
};

ld sarea(pt p, pt q, pt r) { // area com sinal
	return ((q-p)^(r-q))/2;
}

bool ccw(pt p, pt q, pt r) { // se p, q, r sao ccw
	return sarea(p, q, r) > eps;
}

bool isinseg(pt p, line r) { // se p pertence ao seg de r
	pt a = r.p - p, b = r.q - p;
	return eq((a ^ b), 0) and (a * b) < eps;
}

bool interseg(line r, line s) { // se o seg de r intersecta o seg de s
	if (isinseg(r.p, s) or isinseg(r.q, s)
		or isinseg(s.p, r) or isinseg(s.q, r)) return 1;

	return ccw(r.p, r.q, s.p) != ccw(r.p, r.q, s.q) and
			ccw(s.p, s.q, r.p) != ccw(s.p, s.q, r.q);
}

const ld LINF = 1e18;
const int MAX = 51;

int n, m; 
vector<pair<int, ld>> g[MAX]; 
vector<int> pc;
ld d[1 << 10][MAX]; 

ld steiner() {
	int k = pc.size(); // k--;
	for (int mask = 0; mask < (1 << k); mask++) for(int v = 0; v < n; v++) d[mask][v] = LINF;
	for (int v = 0; v < n; v++) d[0][v] = 0;
	for (int i = 0; i < k; ++i) d[1 << i][pc[i]] = 0;
	for (int mask = 1; mask < (1 << k); mask++) {
		for (int a = (mask - 1) & mask; a; a = (a - 1) & mask) {
			int b = mask ^ a;
			if (b > a) break;
			for (int v = 0; v < n; v++)
				d[mask][v] = min(d[mask][v], d[a][v] + d[b][v]);
		}
		priority_queue<pair<ld, int>> pq;
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

	return d[(1 << k) - 1][pc[0]]; // S[k]
}

void solve(){
    cin >> n >> m;
	
    vector<pt> c(n);
	for (int i = 0; i < n; i++) {
    	cin >> c[i];
	}
	
	vector<line> wll(m);
	for (int i = 0; i < m; i++) {
    	cin >> wll[i];
	}

	int s;
	cin >> s;
	for (int i = 0; i < s; i++) {
		int x;
		cin >> x;
		pc.push_back(x-1);
	}

	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			line cable = {c[i], c[j]};
			bool valid = true;

			for (auto w : wll) {
				if (interseg(cable, w)) {
					valid = false;
					break;
				}
			}

			if (valid) {
				ld d = dist(c[i], c[j]);
				g[i].emplace_back(j, d);
				g[j].emplace_back(i, d);
			}
		}
	}

	ld ans = steiner();
	if (ans == LINF) cout << "impossivel\n";
	else cout << fixed << setprecision(3) << ans << '\n';
}

signed main(){
    fastio;
    int t = 1;
    // cin >> t;
    for (int i=0; i<t; i++) solve();
}