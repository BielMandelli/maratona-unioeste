#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
	int n;
    cin >> n;

    vector<int> a;
    for(int i = 0, x; i < n; i++) {
        cin >> x;
        if(x == 0) a.pop_back();
        else a.push_back(x);
    }
    
    int sum = 0;
    for(auto &x : a) sum+= x;

    cout << sum << endl;
}
