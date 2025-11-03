#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

// Using a function for each test case is good practice
void solve() {
    int n;
    std::cin >> n;

    // Since a_i <= n, we can use vectors as frequency maps for efficiency.
    std::vector<int> count(n + 1, 0);
    std::vector<int> first(n + 1, -1);
    std::vector<int> last(n + 1, -1);

    for (int i = 0; i < n; ++i) {
        int val;
        std::cin >> val;
        if (count[val] == 0) {
            first[val] = i;
        }
        count[val]++;
        last[val] = i;
    }

    // Get the sorted list of unique values present in the array
    std::vector<int> unique_vals;
    for (int i = 1; i <= n; ++i) {
        if (count[i] > 0) {
            unique_vals.push_back(i);
        }
    }

    if (unique_vals.size() <= 1) {
        std::cout << 0 << "\n";
        return;
    }

    int m = unique_vals.size();
    
    // dp[i][0] -> max kept from U[0..i] NOT including U[i]
    // dp[i][1] -> max kept from U[0..i] INCLUDING U[i]
    std::vector<std::vector<long long>> dp(m, std::vector<long long>(2, 0));

    // Base case: for the first unique value
    dp[0][0] = 0;
    dp[0][1] = count[unique_vals[0]];

    for (int i = 1; i < m; ++i) {
        int v_curr = unique_vals[i];
        int v_prev = unique_vals[i-1];

        // Case 1: We don't keep the current value v_curr.
        // The best we can do is the max from the previous step.
        dp[i][0] = std::max(dp[i-1][0], dp[i-1][1]);

        // Case 2: We keep the current value v_curr.
        bool conflict = false;
        if (v_curr == v_prev + 1) {
            // A conflict exists if any instance of v_prev appears before an instance of v_curr
            // This is true if the last v_curr is not strictly before the first v_prev.
            if (last[v_curr] >= first[v_prev]) {
                conflict = true;
            }
        }
        
        if (conflict) {
            // If conflict, we cannot have taken v_prev.
            dp[i][1] = count[v_curr] + dp[i-1][0];
        } else {
            // No conflict, we can add to the best result of the previous step.
            dp[i][1] = count[v_curr] + std::max(dp[i-1][0], dp[i-1][1]);
        }
    }

    long long max_kept = std::max(dp[m-1][0], dp[m-1][1]);
    std::cout << n - max_kept << "\n";
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}