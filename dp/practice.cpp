#include <bits/stdc++.h>
using namespace std;

// State dimensions: [idx: 20][tight: 2][leading_zero: 2][prev_digit: 11][prev_prev_digit: 11]
// We use 11 to represent an unassigned/dummy state before digits start.
int dp[20][2][2][11][11];

int digitDP(int idx, bool tight, bool leading_zero, int prev_digit, int prev_prev_digit, const string& s) {
    // Base Case: If we've processed all digits, we can't find any more peaks/valleys.
    if (idx == s.length()) {
        return 0;
    }

    // Return cached value if already computed
    if (dp[idx][tight][leading_zero][prev_digit][prev_prev_digit] != -1) {
        return dp[idx][tight][leading_zero][prev_digit][prev_prev_digit];
    }

    int limit = tight ? (s[idx] - '0') : 9;
    int total_waviness = 0;

    for (int digit = 0; digit <= limit; ++digit) {
        bool next_tight = tight && (digit == limit);
        bool next_leading_zero = leading_zero && (digit == 0);

        int waviness_contributed = 0;

        if (!leading_zero) {
            // We can only check for a peak/valley at 'prev_digit' 
            // if 'prev_prev_digit' actually exists (is valid).
            if (prev_prev_digit != 10) { 
                // Check for Peak
                if (prev_digit > prev_prev_digit && prev_digit > digit) {
                    waviness_contributed = 1;
                }
                // Check for Valley
                else if (prev_digit < prev_prev_digit && prev_digit < digit) {
                    waviness_contributed = 1;
                }
            }
        }

        // Define what the history states look like for the next recursive call
        int next_prev_digit = next_leading_zero ? 10 : digit;
        int next_prev_prev_digit = next_leading_zero ? 10 : prev_digit;

        // 1. Sum up waviness contributed by the current decision path
        // 2. Count the waviness that will be generated downstream
        // If we found a peak/valley, it gets added for ALL valid numbers formed down this branch.
        // To find how many valid suffixes exist, we look at how many ways the rest of the string can be resolved.
        
        // However, a cleaner DP math formulation counts structural waviness at the moment it happens:
        // Every time a match happens, it contributes to the total count. 
        // We need to know how many valid completions exist after this digit to multiply our contribution.
        // Let's compute downstream paths:
        
        int downstream_ways = 0;
        // To accurately get total sum of waviness, our recursive function should return a pair:
        // {count_of_valid_numbers, total_waviness_sum}
        // Let's restructure the return strategy cleanly below.
    }

    return 0; 
}
int main() {
    memset(dp, -1, sizeof(dp));
    string s = "101"; // Example input
    int result = digitDP(0, true, true, 10, 10, s);
    cout << "Total Waviness: " << result << endl;
    return 0;
}