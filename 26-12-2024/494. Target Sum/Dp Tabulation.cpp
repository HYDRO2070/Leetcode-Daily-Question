class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        if (target > sum || target < -sum || (target + sum) % 2 != 0) {
            return 0;
        }

        int offset = sum;
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(2 * sum + 1, 0));
        dp[n][offset] = 1;
        for (int i = n - 1; i >= 0; --i) {
            for (int t = -sum; t <= sum; ++t) {
                int tIndex = t + offset;
                if (tIndex >= 0 && tIndex <= 2 * sum) {
                    int num = nums[i];
                    dp[i][tIndex] = 0;
                    if (t - num >= -sum && t - num <= sum) {
                        dp[i][tIndex] += dp[i + 1][t - num + offset];
                    }
                    if (t + num >= -sum && t + num <= sum) {
                        dp[i][tIndex] += dp[i + 1][t + num + offset];
                    }
                }
            }
        }
        return dp[0][target + offset];
    }
};
