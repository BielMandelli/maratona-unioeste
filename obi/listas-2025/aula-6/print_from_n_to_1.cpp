#include <bits/stdc++.h>
using namespace std;
#define ll long long

void print(int n){
    if(n == 0) return;
    cout << n << (n-1 > 0 ? " " : "");
    print(n-1);
}

int main(){
    int n;
    cin >> n;

    print(n);

    return 0;
}