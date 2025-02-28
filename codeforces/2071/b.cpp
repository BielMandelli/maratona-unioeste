#include <bits/stdc++.h>
#define int long long
using namespace std;

bool isPerfectSquare(int x){
    int sq = sqrt(x);
    if(sq*sq == x) return true;
    else return false;
}
 
signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        if(n == 1) {
            cout << "-1" << endl;
            continue;
        }

        vector<int> perm;
        set<int> perfSq, disp;

        int sum = 0;
        for (int i = 1; i <= n; i++){
            if(i < 5000) perfSq.insert(i*i);
            disp.insert(i);
            sum += i;
        }

        if(perfSq.find(sum) != perfSq.end())
        {
            cout << "-1" << endl;
            continue;
        }

        sum = 0;
        while(!disp.empty()){
            for(auto it = disp.begin(); it != disp.end(); it++){
                if(!isPerfectSquare(sum + *it)){
                    sum += *it;
                    perm.push_back(*it);
                    disp.erase(it);
                    break;
                }
            }
        }

        for (auto x : perm) cout << x << " ";
        cout << endl;
    }

    return 0;
}