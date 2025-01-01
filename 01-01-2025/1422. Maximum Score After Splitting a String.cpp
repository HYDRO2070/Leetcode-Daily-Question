class Solution {
public:
    int maxScore(string s) {
        int ans = 0;
        int n = s.size();
        vector<int> prefix(n,0);
        int one = 0;
        if(s[0] == '0') prefix[0] = 1;

        for(int i = 1;i < n;i++){
            prefix[i] = prefix[i-1];
            if(s[i] == '0') prefix[i]++;
        }
        for(int i = n-1;i > 0;i--){
            one += (s[i] == '1') ? 1 : 0;
            int temp = one;
            temp += prefix[i-1];
            ans = max(ans,temp);
        }
        return ans;
    }
};
