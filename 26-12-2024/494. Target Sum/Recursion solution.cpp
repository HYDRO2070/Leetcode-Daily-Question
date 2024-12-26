class Solution {
    private:
    int solve(vector<int>& nums, int t,int i){
        if(i == nums.size()){
            if(t == 0) return 1;
            return 0;
        }
        int temp = abs(nums[i]);
        int ans = 0;
        ans += solve(nums,t-temp,i+1);
        ans += solve(nums,t+temp,i+1);
        return ans;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums,target,0);
    }
};
