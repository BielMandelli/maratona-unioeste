#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) (int) (a).size()
#define ll long long
#define ld long double
#define pb push_back

typedef long long C;
typedef complex<C> P;
#define X real()
#define Y imag()

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

#define int long long

map<string, pair<int,int>> dic;
vector<string> orig, base;
int n, m;

vector<string> search_candidates(vector<string> ph, int k){
    vector<string> cand;
    for (int i = 0; i < m; i++)
    {
        int l = i, r = 0;
        while(l < m && r < k && base[l] == ph[r] ){
            r++;
            l++;
        }

        if(r == k && l < m) cand.push_back(base[l]);
    }

    return cand;
}

string comum(string s1, string s2){
    for (int i = 0; i < n; i++)
    {
        if(s1 == orig[i]) return s1;
        if(s2 == orig[i]) return s2;
    }
}

int mult(pair<int,int> v1, pair<int,int> v2) { return (v1.first*v2.first) + (v1.second*v2.second); }

string calc(vector<string> cand){
    int bst = 0, sum = 0;
    string ans;
    for (auto [s,d] : dic){
        sum = 0;
        for (auto c : cand){
            sum += mult(d, dic[c]);
        }

        // dbg(s, sum, bst);
        if(sum > bst) { bst = sum; ans = s; }
        else if (sum == bst) ans = comum(ans, s);
    }
    return ans;
}

string search_base(vector<string> ph, int k){
    vector<string> cand;
    while(k){
        while(ph.size() > k) ph.erase(ph.begin());
        
        cand = search_candidates(ph, k);
        if(cand.empty()) k--;
        else break;
    }
    
    if(k == 0) return "*";
    return calc(cand);
}

void read(int k){
    int f;
    cin >> f;
    vector<string> ph(f);
    for(auto &x : ph) cin >> x;

    string ans = search_base(ph, k);

    for(auto x : ph) cout << x << ' ';
    cout << ans << endl;
}

void solution(){
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        int x,y;
        cin >> s >> x >> y;
        dic[s] = {x,y};
        orig.push_back(s);
    }
    
    cin >> m;
    base.resize(m);
    for(auto &x : base) cin >> x;

    int q, k;
    cin >> q >> k;
    while(q--) read(k);
}

signed main(){
    fastio;
    int t=1;
    //cin >> t;
    for (int i=0; i<t; i++){
        solution();
    }
}