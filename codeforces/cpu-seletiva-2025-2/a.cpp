#include <bits/stdc++.h>
using namespace std;
#define beeu cin.tie(0)->sync_with_stdio(0)
#define int long long
const int MOD = 1e9+7;

signed main(){
    beeu;

    string s;
    vector<int> freq(26, 0);
    vector<char> arr = {'a','b','c','d','e','f','g','h','i','j','k' ,'l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        freq[s[i]-'a']++;
    }
    
    int m = 0;
    char ans;
    for (int i = 0; i < 26; i++)
    {
        if(freq[i] > m) {
            m = freq[i];
            ans = arr[i];
        }
}
    
    cout << ans << endl;

    return 0;
} 
