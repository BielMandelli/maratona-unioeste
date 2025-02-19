#include <bits/stdc++.h>
#define int long long
using namespace std;
 
signed main(){
    int n;
    cin >> n;
    vector<pair<int,int>> vert(n);

    for (auto &x : vert) cin >> x.first >> x.second;

    if(n == 1) {
        cout << -1 << endl;
        return 0;
    }

    int h = 0, b = 0;
    if(vert[0].first != vert[1].first){
        b = abs(vert[0].first - vert[1].first);
    }  else if (n>2) {
        b = abs(vert[1].first - vert[2].first);
    } 

    if (vert[0].second != vert[1].second) {
        h = abs(vert[0].second - vert[1].second);
    }   else if (n>2) {
        h =abs(vert[1].second - vert[2].second);
    }

    if(!b or !h) {
        cout << -1 << endl;
        return 0;
    }

    cout << b*h << endl;

    return 0;
}