class Solution {
    // using recursion + dp
    // int solve(vector<int>& values,int i,vector<int> &dp){
    //     if(i == values.size()-1) return 0;
    //     if(dp[i] != -1) return dp[i];
    //     int ans = 0;

    //     for(int j = i+1;j < values.size();j++){
    //         ans = max(ans,max(values[i] + values[j] + i - j,solve(values,j,dp)));
    //     }
    //     dp[i] = ans;
    //     return dp[i];

    // }
    // using dp
    // int solve(vector<int>& values){
    //     int n = values.size();
    //     vector<int> dp(n+1,-1);
    //     dp[n-1] = 0;
    //     for(int i = n-2;i >= 0;i--){
    //         int ans = 0;
    //         for(int j = i+1;j < values.size();j++){
    //             ans = max(ans,max(values[i] + values[j] + i - j,dp[j]));
    //         }
    //         dp[i] = ans;
    //     }
    //     return dp[0];
    // }
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        // vector<int> dp(values.size()+1,-1);
        // return solve(values,0,dp);
        // return solve(values);


        int maxScore = 0;
        int maxI = values[0];
        for (int j = 1; j < values.size(); ++j) {
            maxScore = max(maxScore, maxI + values[j] - j);
            maxI = max(maxI, values[j] + j);
        }

        return maxScore;
    }
};
