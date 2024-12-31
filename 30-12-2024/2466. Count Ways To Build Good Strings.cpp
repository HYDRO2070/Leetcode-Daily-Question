const int MOD = 1e9 + 7;

class Solution {
private:
    // using recursion + memo
    // int solve(int low, int high, int zero, int one, int size, vector<int>&
    // dp) {
    //     if (size > high) return 0;
    //     if (dp[size] != -1) return dp[size];

    //     int ans = (low <= size && size <= high) ? 1 : 0;

    //     ans = (ans + solve(low, high, zero, one, size + zero, dp)) % MOD;
    //     ans = (ans + solve(low, high, zero, one, size + one, dp)) % MOD;

    //     dp[size] = ans;
    //     return dp[size];
    // }

    // using tabulation
    int solve(int low, int high, int zero, int one) {
        vector<int> dp(high + 1, 0);

        for (int size = high; size >= 0; size--) {
            int ans = (low <= size && size <= high) ? 1 : 0;
            if (size + zero <= high)
                ans = (ans + dp[size + zero]) % MOD;
            if (size + one <= high)
                ans = (ans + dp[size + one]) % MOD;

            dp[size] = ans;
        }
        return dp[0];
    }

public:
    int countGoodStrings(int low, int high, int zero, int one) {
        // vector<int> dp(high + 1, -1);
        // return solve(low, high, zero, one, 0, dp);
        return solve(low, high, zero, one);
    }
};
