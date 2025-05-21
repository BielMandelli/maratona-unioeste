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
        string s1,s2;
        cin >> s1 >> s2;

        vector<int> rangeS1, rangeS2;
        int seq = 1;

        for (int i = 0; i < s1.size(); i++)
        {   
            if(i+1 != s1.size() && s1[i] == s1[i+1]) seq++;
            else {
                rangeS1.push_back(seq*2);
                seq = 1;
            }
        }
        
        for (int i = 0; i < s2.size(); i++)
        {   
            if(i+1 != s2.size() && s2[i] == s2[i+1]) seq++;
            else {
                rangeS2.push_back(seq);
                seq = 1;
            }
        }

        bool valid = true;

        if(s1[0] != s2[0] or rangeS1.size() != rangeS2.size()) valid = false;

        for (int i = 0; i < rangeS1.size(); i++)
        {
            if(!valid) break;
            if(rangeS1[i]/2 > rangeS2[i] or rangeS1[i] < rangeS2[i]) valid = false;
        }

        cout << ((valid) ? "YES" : "NO") << endl;
    }
    
    return 0;
}