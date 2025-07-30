#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int n;
    cin >> n;

    vector<int> a(n), maxRight(n), maxLeft(n);

    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    maxLeft[0] = a[0];
    for (int i = 1; i < n; i++){
        maxLeft[i] = max(maxLeft[i-1], a[i]);
    }

    maxRight[n-1] = a[n-1];
    for (int i = n-2; i >= 0; i--){
        maxRight[i] = max(maxRight[i+1], a[i]);
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++){
        int depth = min(maxLeft[i], maxRight[i]) - a[i];
        if(depth >= 1) ans++;
    }
    
    cout << ans << endl;

    return 0;
}