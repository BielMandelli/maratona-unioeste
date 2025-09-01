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

void solution(){
    int c, n;
    cin >> c >> n;
    vector<int> a(c);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a[x]++;
    }

    bool valid = false;

    int g = c/n;
    vector<int> groups(n);

    bool possible = true;    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < g; j++){            
            groups[i] += a[j + i*g];
        }        
        if(groups[i] != 1) possible= false;
    }
    if(possible) valid = true;

    for(int i = 1; i < g; i++){           
        possible = true; 
        for(int j = 0; j < n; j++){
            int st = j*g + i;
            int en = ((j+1)*(g) + i - 1) % c;            
            groups[j] -= a[st-1];
            groups[j] += a[en];
            if(groups[j] != 1) possible = false;            
        }
        if(possible) valid = true;
    }

    cout << (valid ? "S" : "N") << endl;
}

signed main(){
    fastio;
    int t=1;
    //cin >> t;
    for (int i=0; i<t; i++){
        solution();
    }
}