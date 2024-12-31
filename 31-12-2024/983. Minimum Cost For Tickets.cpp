class Solution {
private:
    // int solve(vector<int>& days, vector<int>& costs,int index,vector<int> &dp) {
    //     int n = days.size();
    //     if(index >= n) return 0;
    //     if(dp[index] != -1) return dp[index];
    //     // cout<<index<<endl;

    //     int ans = costs[0] + solve(days,costs,index+1,dp);

    //     int i;
        
    //     for(i = index;i < n && days[i] < days[index]+7;i++);

    //     ans = min(ans,costs[1] + solve(days,costs,i,dp));

    //     for(i = index;i < n && days[i] < days[index]+30;i++);

    //     ans = min(ans,costs[2] + solve(days,costs,i,dp));

    //     dp[index] = ans;
    //     return dp[index];

    // }
    int solve(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n+1,0);
        dp[n] = 0;


        for(int index = n-1;index >= 0;index--){
            int ans = costs[0] + dp[index+1];

            int i;
            
            for(i = index;i < n && days[i] < days[index]+7;i++);

            ans = min(ans,costs[1] + dp[i]);

            for(i = index;i < n && days[i] < days[index]+30;i++);

            ans = min(ans,costs[2] + dp[i]);

            dp[index] = ans;
        }

        return dp[0];
    }

public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // vector<int> dp(days.size()+1,-1);
        // return solve(days,costs,0,dp);
        return solve(days,costs);
    }
};
