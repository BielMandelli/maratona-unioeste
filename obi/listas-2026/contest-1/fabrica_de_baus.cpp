#include <bits/stdc++.h>
using namespace std;

#define ll long long 

vector<ll> b(8);
int n;

ll brute(int qnt){
    ll ans = 0;
    if(qnt == 8) return 1;

    for (int i = 0; i < n; i++)
    {
        if(b[i]){
            b[i]--;
            ans += brute(qnt+1);
            b[i]++;
        }
    }
    return ans;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    
    cout << brute(0) << endl;
}