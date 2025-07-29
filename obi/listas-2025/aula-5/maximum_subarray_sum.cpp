#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    ll sum = 0, min_sum = 0, max_sum = LLONG_MIN;

    for (int i = 0; i < n; i++) {
        sum += a[i];
        max_sum = max(max_sum, sum - min_sum);
        min_sum = min(min_sum, sum);
    }
    
    cout << max_sum << endl;

    return 0;
}