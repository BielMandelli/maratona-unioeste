#include <bits/stdc++.h>
#define int long long
using namespace std;
 
signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(0);
 
    int n, buy = 0;
    cin >> n;
    vector<char> key(n-1), door(n-1);
    multiset<char> disp;

    for (int i = 0; i < n-1; i++){
        cin >> key[i] >> door[i];
    }

    for (int i = 0; i < n-1; i++){
        disp.insert(key[i]);
        auto it = disp.find(tolower(door[i]));
        if(it != disp.end()) disp.erase(it);
        else buy++;
    }

    cout << buy << endl;
 
    return 0;
}