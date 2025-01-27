#include <bits/stdc++.h>
#define int long long
using namespace std;
#define MOD = 1e9 + 7;

static vector<int> sol_n6  = {1,1,2,3,1,2};
static vector<int> sol_n7  = {1,1,2,3,1,2,3};
static vector<int> sol_n8  = {1,1,2,3,1,2,3,1};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t; 
    while(t--) {
        int n;
        cin >> n;

        if(n == 6) {
            for(int i=0; i<6; i++){
                cout << sol_n6[i] << (i+1<6?' ':'\n');
            }
        }
        else if(n == 7) {
            for(int i=0; i<7; i++){
                cout << sol_n7[i] << (i+1<7?' ':'\n');
            }
        }
        else if(n == 8) {
            for(int i=0; i<8; i++){
                cout << sol_n8[i] << (i+1<8?' ':'\n');
            }
        }
        else {

            for(int i=1; i<=n; i++){
                if(i % 2 == 1) cout << 1;   
                else           cout << 4;    

                cout << (i<n ? ' ' : '\n');
            }
        }
    }

    return 0;
}