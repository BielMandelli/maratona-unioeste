#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    vector<int> cnt(26);
    for (char c : s) cnt[c - 'A']++;

    string front = "", back = "";
    char mid = '\0';
    bool oddUsed = false;
    bool valid = true;

    for (int i = 0; i < 26; i++) {

        while (cnt[i] >= 2) {
            front += i + 'A';
            back += i + 'A';
            cnt[i] -= 2;
        }

        if (cnt[i]) {
            if (oddUsed) {
                valid = false;
                break;
            } else {
                oddUsed = true;
                mid = i + 'A';
            }
        }
    }

    if (!valid) {
        cout << "NO SOLUTION" << endl;
    } else {
        reverse(back.begin(), back.end());
        if (mid != '\0') cout << front + mid + back << endl;
        else cout << front + back << endl;
    }

    return 0;
}
