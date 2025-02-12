#include <bits/stdc++.h>
#define int long long
const int MOD = 1e9 + 7;
using namespace std;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> dp(2e5, 0);

    for (int i = 0; i < 9; i++) dp[i] = 2; //Tamanho do número com operações entre 0 e 8
    dp[9] = 3; //9 = Ganha digito novo
    for (int i = 10; i < 2e5; i++) dp[i] = ((dp[i-9] + dp[i-10])%MOD); //Calcula o tamanho de números até 2e5
 
    int t;
    cin >> t;
 
    while(t--) {
        int n, m;
        cin >> n >> m;

        int ans = 0, aux;
        while(n > 0){
            aux = n%10;
            ans += ((m+aux < 10) ? 1 : dp[m-10+aux]); //Define a resposta com base nos valores calculados
            ans %= MOD;
            n /= 10;
        }
        
        cout << ans << endl;
    }
    
    return 0;
}