#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n;
    cin >> n;

    if (n == 1 or n == 2) cout << 0 << endl;
    else {
        int mod = n%3;
        int sum = 1;
        if(!mod) sum=0;
        cout << (n/3)*2 + sum << endl;
    }
}

signed main(){
    int cases = 1;
    cin >> cases;
    for (int i = 0; i<cases;i++) solve();
}