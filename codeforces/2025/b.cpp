#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 1e9 + 7;
 
signed main(){
    
	int t; 
    cin >> t;
	vector<int> pot(t);
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < t; j++)
			cin >> pot[j];
	
	vector<int> dp(1 + *max_element(pot.begin(), pot.end()), 1);

	for (int i = 1; i < dp.size(); i++) dp[i] = (2LL * dp[i - 1]) % MOD;
	
	for (int k : pot)cout << dp[k] << endl;
	
    return 0;
}