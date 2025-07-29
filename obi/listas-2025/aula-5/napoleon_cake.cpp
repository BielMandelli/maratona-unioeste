#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }

        reverse(a.begin(), a.end());
        
        vector<int> diff(n+1);
        for (int i = 0; i < n; i++){
            if(a[i] == 0) continue;
            diff[i]++;
            diff[min(n, i+a[i])]--;
        }
        
        vector<int> psum(n+1);
        psum[0] = diff[0];
        for (int i = 1; i <= n; i++){
            psum[i] = psum[i-1] + diff[i];
        }
        
        for (int i = n-1; i >= 0; i--){
            cout << (psum[i] ? '1' : '0') << " ";
        }
        cout << endl;
    }
    
    

    return 0;
}