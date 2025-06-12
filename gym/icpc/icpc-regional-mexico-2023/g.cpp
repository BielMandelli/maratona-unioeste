#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
#define int long long

signed main(){
    fastio;

    int n;
    cin >> n;

    if(n==1) {
        cout << "Jane" << endl;
        return 0;
    }

    int winner = 1, upd = 2, aux = 0;
    for(int i = 2; i <= n; i++){
        if(aux == upd) {
            winner = !winner;
            aux = 0;
            if(winner) upd++;
        }
        aux++;
    }

    if(!winner) cout << "Jane" << endl;
    else cout << "John" << endl;
}