#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int n;
    cin >> n;

    int cont = 1, ans = 0, x, last;
    for (int i = 0; i < n; i++)
    {
        last = x;
        cin >> x;
        if(i == 0) continue;
        if(x != last) {
            ans = max(ans, cont);
            cont = 1;
        } else cont++;
    }

    ans = max(ans, cont);
    
    cout << ans << endl;

    return 0;
}