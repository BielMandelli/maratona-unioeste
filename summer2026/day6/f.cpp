#include <bits/stdc++.h>
using namespace std;

#define ld long double
#define int long long

#define vi vector<int>
#define vvi vector<vi>

const int MOD = 1e9+7;

void solve(){
    int n; cin >> n;
    string s; cin >> s;

    int k = 1;
    int a=0,ab=0,abc=0;
    for (int i = 0; i < n; i++){
        if(s[i] == 'a') a = (a+k)%MOD;
        else if (s[i] == 'b') ab = (ab+a)%MOD;
        else if (s[i] == 'c') abc = (abc+ab)%MOD;
        else {
            abc = (3*abc+ab)%MOD;
            ab = (3*ab+a)%MOD;
            a = (3*a+k)%MOD;
            k= (3*k)%MOD;
        }
    }

    cout << abc << endl;
}

signed main(){
    int cases = 1;
    //cin >> cases;
    for (int i = 0; i<cases;i++) solve();
}