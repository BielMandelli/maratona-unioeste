#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long l, r;
        cin >> l >> r;

        cout << r << " " << r-1 << " " << l << endl;
    }

    return 0;
}