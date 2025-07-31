#include <bits/stdc++.h>
using namespace std;
#define ll long long

void print(int n){
    if(n <= 0) return;
    print(n/2);
    cout << n%2;
}

int main(){
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        print(n);
        cout << endl;
    }
    
    return 0;
}