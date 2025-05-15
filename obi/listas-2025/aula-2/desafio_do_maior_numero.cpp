#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n, ans = 0;
    cin >> n;
    
    while(n > 0){
        ans = max(ans, n);
        cin >> n;
    }

    cout << ans << endl;
    
    return 0;
}