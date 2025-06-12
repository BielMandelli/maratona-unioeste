#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

vector<vector<int>> a(3, vector<int>(6));

int solve(int d){
    for (int i = 0; i < 3; i++) {
        int win = 0, tot = 0;
        if(i == d) continue;
        for (int j = 0; j < 6; j++) {
            for (int k = 0; k < 6; k++) {
                if(a[d][j] == a[i][k]) continue;
                tot++;
                if(a[d][j] > a[i][k]) win++;
            }
        }
        if(2*win < tot or !win) return false;
    }
    return true;
}

signed main() {
    bieo;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 6; j++)
            cin >> a[i][j];
    
    int mx = 0, bst = 0;
    for (int i = 0; i < 3; i++) {
        if(solve(i)){
            bst = i+1;
            break;
        }
    }

    if(bst) cout << bst << endl;
    else cout << "No dice" << endl;
    
    return 0;
}
