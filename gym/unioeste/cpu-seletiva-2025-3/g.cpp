#include <bits/stdc++.h>
using namespace std;
#define beeu cin.tie(0)->sync_with_stdio(0)
#define int long long
const int MOD = 1e9+7;

signed main(){
    beeu;

    int n;
    cin >> n;

    int ans = 1, sum = 0, cur = 0;
    for (int i = 2; i <= sqrt(n); i++){
        sum = 1 + i;
        cur = i;
        while(true){
            cur *= i;
            sum += cur;
            if(sum > n) break;
            if(!(n % sum)) ans++;  
        }
    }

    for (int i = 1; i <= sqrt(n); i++){
        int res;
        if(!(n%i)){
            if(i > 2) ans++;

            res = n/i;
            if(res != i && !(res<3)) ans++;
        }
    }

    cout << ans << endl;
    return 0;
} 
