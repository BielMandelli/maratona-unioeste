#include <bits/stdc++.h>

using namespace std;

int main() {
    int clicks;
    int button;
    int lampA = 0, lampB = 0;

    cin >> clicks;
    for(int i = 0; i < clicks; i++) {
        cin >> button;

        if (button == 1) lampA = !lampA;
        else {
            lampA = !lampA;
            lampB = !lampB;
        }
    }

    cout << lampA << endl << lampB;
}