class Solution {
    private:
    int solve(vector<int>& nums, int t,int i,vector<vector<int>>& dp,int offset){
        if(i == nums.size()){
            if(t == 0) return 1;
            return 0;
        }
        if(dp[i][t+offset] != -1) return dp[i][t+offset];
        int temp = abs(nums[i]);
        int ans = 0;
        ans += solve(nums,t-temp,i+1,dp,offset);
        ans += solve(nums,t+temp,i+1,dp,offset);
        dp[i][t+offset] = ans;
        return dp[i][t+offset];
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<vector<int>> dp(nums.size(),vector<int>(4002,-1));
        return solve(nums,target,0,dp,2000);
    }
};
