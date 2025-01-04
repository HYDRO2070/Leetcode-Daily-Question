class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long long sum = accumulate(nums.begin(),nums.end(),0ll);
        long long tempsum = 0;
        int ans = 0;
        // for(int i =0;i < n;i++) sum += nums[i];
        for(int i = 0;i < n-1;i++){
            tempsum += nums[i];
            if(tempsum >= sum - tempsum) ans++;
        }        
        return ans;
    }
};
