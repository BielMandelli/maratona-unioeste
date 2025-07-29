#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int n,q;
    cin >> n >> q;

    vector<int> a(n+1);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    
    vector<ll> psum(n+1);
    for (int i = 1; i <= n; i++){
        psum[i] = psum[i-1] + a[i];
    }
    
    while (q--){
        int a,b;
        cin >> a >> b;
        cout << psum[b] - psum[a-1] << endl;
    }
    

    return 0;
}