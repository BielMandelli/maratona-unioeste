#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long

signed main()
{
    bieo;

    int t;
    cin >> t;

    while(t--){
        string newName = "";

        for (int i = 0; i < 3; i++)
        {
            string s;
            cin >> s;
            newName += s[0];
        }
        
        cout << newName << endl;
    }
    
    return 0;
}