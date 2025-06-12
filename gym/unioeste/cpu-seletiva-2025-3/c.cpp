#include <bits/stdc++.h>
using namespace std;
#define beeu cin.tie(0)->sync_with_stdio(0)
#define int long long
const int MOD = 1e9+7;

signed main(){
    beeu;

    int n, k;
    cin >> n >> k;
    set<int, greater<int>> s, s2;

    int aux, ans = 0;
    for(int i = 0; i < n; i++){
        cin >> aux;
        s.insert(aux);
    }

    for(auto x : s){
        if(s2.count(x*k) == 0) s2.insert(x);
    }

    // for(auto x : s2) cout << "s2 x: " << x << endl;

    cout << s2.size() << endl;

    return 0;
} 
