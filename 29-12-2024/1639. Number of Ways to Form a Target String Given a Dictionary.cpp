const int MOD = 1e9 + 7;

// recursion solution
// class Solution {
//     long long solve(vector<string>& words, string target,int index,string s){
//         if(index >= words[0].size()) return 0;
//         if(s.size() == target.size()){
//             if(s == target) return 1;
//             return 0;
//         }
//         long long ans = 0;
//         for(string st : words){
//             for(int i = index;i < st.size()-1;i++){
//                 ans += (solve(words,target,i+1,s+st[i]));
//             }
//         }
//         return ans;
//     }
// public:
//     int numWays(vector<string>& words, string target) {
//         return solve(words,target,0,"") % MOD;
//     }
// };


// recursion + memo
class Solution {
    // long long solve(vector<string>& words, string& target, int index, int targetIndex, vector<vector<long long>>& dp) {
    //     if (targetIndex >= target.size()) return 1;
    //     if (index >= words[0].size()) return 0;

    //     if (dp[index][targetIndex] != -1) return dp[index][targetIndex];

    //     long long ans = 0;

    //     int count = 0;
    //     for (string& st : words) {
    //         if (st[index] == target[targetIndex]) {
    //             count++;
    //         }
    //     }

    //     if (count > 0) {
    //         ans += (1LL * count * solve(words, target, index + 1, targetIndex + 1, dp)) % MOD;
    //     }

    //     ans += solve(words, target, index + 1, targetIndex, dp);

    //     dp[index][targetIndex] = ans % MOD;
    //     return dp[index][targetIndex];
    // }

    // using tabulation + memo
    long long solve(vector<string>& words, string& target) {
        vector<vector<long long>> dp(words[0].size()+1, vector<long long>(target.size()+1, 0));
        int n = words[0].size();
        int m = target.size();

        vector<vector<int>> freq(26, vector<int>(n, 0));
        for (string& word : words) {
            for (int j = 0; j < n; ++j) {
                freq[word[j] - 'a'][j]++;
            }
        }

        for(int i = 0;i <= n;i++){
            dp[i][m] = 1;
        }


        for(int index = n-1;index >= 0;index--){
            for(int targetIndex = m-1;targetIndex >= 0;targetIndex--){
                long long ans = dp[index + 1][targetIndex];

                
                // for (string& st : words) {
                //     if (st[index] == target[targetIndex]) {
                //         count++;
                //     }
                // }
                char targetChar = target[targetIndex];
                int count = freq[targetChar - 'a'][index];
                if (count > 0) {
                    ans += (1LL * count * dp[index+1][targetIndex+1]) % MOD;
                }

                dp[index][targetIndex] = ans % MOD;
            }
        }
        return dp[0][0];
    }

public:
    int numWays(vector<string>& words, string target) {
        // vector<vector<long long>> dp(words[0].size(), vector<long long>(target.size(), -1));
        // return solve(words, target, 0, 0, dp);
        return solve(words,target);
    }
};
