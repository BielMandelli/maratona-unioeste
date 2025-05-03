#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long

bool check(vector<int> &arr){
    for (int i = 0; i <= arr.size(); i++)
    {
        if(i+1 != arr[i]) return false;
    }
    
    return true;
}

signed main()
{
    bieo;
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x : a) cin >> x;

    int ans = n-1;
    for (int i = n-2; i >=0; i--)
    {
        if(a[i] < a[i+1]) ans = i;
        else break;
    }
    
    cout << ans << endl;

    return 0;
}