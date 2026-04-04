#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define ll long long 
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
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

struct qy {
    int l, r, idx;
};

void solution(){
    int n;
    cin >> n;

    vector<int> a(n);
    for(auto &x : a) cin >> x;
    BIT<int> bit(n);

    int q;
    cin >> q;
    vector<qy> qu(q);
    for (int i = 0; i < q; i++)
    {
        cin >> qu[i].l >> qu[i].r;
        qu[i].l--;
        qu[i].r--;
        qu[i].idx = i;
    }
    
    sort(qu.begin(), qu.end(), [](qy &a, qy &b){
        return a.r < b.r;
    });

    map<int,int> freq;
    vector<int> ans(q);

    int cur = -1;
    for(auto [l,r,id] : qu){
        while(cur < r){
            cur++;
            int v = a[cur];

            if(freq.count(v)) bit.add(freq[v], -1);

            bit.add(cur, 1);
            freq[v] = cur;
        }

        ans[id] = bit.query(r) - (l > 0 ? bit.query(l-1) : 0);
    }
    
    for (int i = 0; i < q; i++)
    {
        cout << ans[i] << endl;
    }
    
}

signed main(){
    fastio;
    int cases = 1;
    //cin >> cases;
    for (int i = 0; i < cases; i++){
        solution();
    }
    
}
