#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bieo cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

void div(int x, map<int, int>&divs){
    int i = 2;
    while(i * i <= x){
        while (x % i == 0){
            divs[i]++;
            x /= i;
        }
        i++;
    }
    if(x > 1) divs[x]++;
}

signed main() {
    bieo;

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        map<int, int> divs; 
        for(auto &x : a) {
            cin >> x;
            div(x, divs);
        }
        
        int valid = true;
        for(auto x : divs){
            if(!valid) break;
            if(x.second%n) valid = false;
        }

        if(valid) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    
        
    return 0;
}
