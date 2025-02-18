#include <bits/stdc++.h>
using namespace std;
#define int long long

int sum_of_digits(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

pair<int, int> split_number(int n) {
    if (n % 2 == 0) {
        return {n/2, n/2};
    }

    if (n % 10 != 9) {
        return {(n+1)/2, (n-1)/2};
    }

    auto [x_prime, y_prime] = split_number(n/10);

    int x1 = 10 * x_prime + 4, y1 = 10 * y_prime + 5;
    int x2 = 10 * x_prime + 5, y2 = 10 * y_prime + 4;

    return (abs(sum_of_digits(x1) - sum_of_digits(y1)) <= 1) ? make_pair(x1, y1) : make_pair(x2, y2);
}

signed main() {
    int t;
    cin >> t;

    while (t--){
        int n;
        cin >> n;


        pair<int,int> xy = split_number(n);
        
        cout << xy.first << " " << xy.second << endl;
    }

    return 0;
}