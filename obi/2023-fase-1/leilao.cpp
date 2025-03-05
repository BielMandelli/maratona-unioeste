#include <bits/stdc++.h>
#define int long long
using namespace std;
 
signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(0);

    int n, x;
    string s;
    cin >> n;

    int bestX = 0;
    string bestS;
    for (int i = 0; i < n; i++)
    {
        cin >> s >> x;
        if(bestX < x) {
            bestX = x;
            bestS = s;
        }
    }

    cout << bestS << endl << bestX << endl;
    
    return 0;
}