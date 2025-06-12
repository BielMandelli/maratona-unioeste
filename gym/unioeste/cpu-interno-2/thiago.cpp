#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<int> p;

void f(int x){
    if(x == 0) return;
    int aux = p[x];
    p[x] = p[x-1];
    p[x-1] = aux; 

    f(x-1);
}

signed main(){
    int t;
    cin >> t;
    
    for (int i = 1; i<= t; i++) p.push_back(i);
    f(t-1);

    for (auto x : p) cout << x << " ";
    cout << endl;
    
    return 0;
}