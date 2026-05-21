#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define int long long 
#define aint(a) a.begin(), a.end()
#define raint(a) a.rbegin(), a.rend()
#define sz(a) ((int) (a).size())
#define ld long double

void dbg_out(string s) {cerr << endl;}
template<typename H, typename ...T>
void dbg_out(string s, H h, T... t){
    do{cerr << s[0]; s = s.substr(1);
    } while(sz(s) && s[0] != ',');
    cerr << " = " << h;
    dbg_out(s, t...);
}

#ifdef DEBUG
#define dbg(...) dbg_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 42
#endif

template <class T> class BIT {
  private:
	int size;
	vector<T> t;
	vector<T> arr;

  public:
	BIT(int size): size(size), t(size + 1), arr(size){}

	void set(int idx, T val){ add(idx, val - arr[idx]); }

	void add(int idx, T val){
		arr[idx] += val;
		for (idx++; idx <= size; idx += idx & -idx) t[idx] += val;
	}

	T query(int idx){
		T ans = 0;
		for (idx++; idx; idx -= idx & -idx) ans += t[idx];
		return ans;
	}
};

const int MX = 1e6+3;

void solution(){
    int n, q;
    cin >> n >> q;

    vector<vector<int>> rl(MX);
    for (int i = 0; i < n; i++)
    {
        int l,r;
        cin >> l >> r;
        rl[r].push_back(l);
    }

    vector<int> ans(q, 0); 
    
    vector<vector<pair<int,int>>> lid(MX);

    for(int i = 0; i < q; i++){
        int k;
        cin >> k;

        vector<int> v(k);
        v.push_back(0);
        v.push_back(MX - 1);

        for(int j = 0; j < k; j++) cin >> v[j];

        sort(v.begin(), v.end());

        for(int j = 0; j + 1 < sz(v); j++){
            int l = v[j];
            int r = v[j+1];
            lid[r].push_back({l, i});
        }
    }

    BIT<int> bit(MX);
    int total = 0; 

    for(int r = 0; r < MX; r++){
        for(auto [l, id] : lid[r]){
            int p = total - bit.query(l);
            ans[id] += p;
        }

        for(int l : rl[r]){
            bit.add(l, 1);
            total++;
        }
    }

    for(int i = 0; i < q; i++) cout << n - ans[i] << endl;
}

signed main(){
    fastio;
    int cases = 1;
    //cin >> cases;
    for (int i = 0; i < cases; i++){
        solution();
    }
    
}
