#include <bits/stdc++.h>
using namespace std;
#define ll long long

int fat(int n){
    if(n == 1 or n == 0) return 1;
    return n*fat(n-1);
}

int main(){
    int n;
    cin >> n;

    cout << fat(n) << endl;
    
    return 0;
}