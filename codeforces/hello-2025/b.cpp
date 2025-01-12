#include <bits/stdc++.h>
#define int long long
using namespace std;
bool isPossible = true;

signed main () {
    int t;

    cin >> t;

    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> elements(n, 0);
        vector<int> countElements(n, 0);

        for (int i = 0; i < n; i++){
            cin >> elements[i];
        }

        sort(elements.begin(), elements.end());

        for (int i = 1, j = 0; i <= n; i++){
            if(elements[i-1] == elements[i]){
                countElements[j]++;
                continue;
            }
            countElements[j]++;
            j++;
        }

        sort(countElements.begin(), countElements.end());

        int j = 0;
        while (k > 0)
        {
            if(countElements[j] == 0) {
                j++;
                continue;
            }
            if(countElements[j] <= k) {
                k -= countElements[j];
                countElements[j] = 0;
            } else {
                break;
            }
            j++;
        }

        int count = 0;

        for (int i = 0; i < n; i++)
        {
            if(countElements[i] > 0){
                count++;
            }
        }

        if(count == 0) count++;
        cout << count << endl;

    }
    return 0;
}