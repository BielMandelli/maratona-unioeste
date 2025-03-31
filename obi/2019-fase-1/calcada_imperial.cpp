#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
const int MOD = 1e9 + 7;

signed main()
{
    bieo;
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x : a) cin >> x;

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int cur = a[i];
        int mAns = 1;
        for (int j = i+1; j < n; j++)
        {
            int jcur = a[j];
            mAns = 0;
            int ant = -1;
            for (int k = 0; k < n; k++)
            {
                if(a[k] == cur or a[k] == jcur){
                    if(a[k]!=ant){
                        mAns++;
                        ant = a[k];
                    }
                }
            }
            ans = max(ans, mAns);
        }
        ans = max(ans, mAns);
    }
    
    cout << ans << endl;
    
    return 0;
}