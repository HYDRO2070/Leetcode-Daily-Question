class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> R(26,0);
        for(auto &u : s)
        {
            R[u-'a']++;
        }
        vector<int> L(26, 0);
        
        unordered_set<int> S;
        
        for(int i = 0; i < s.length(); i++)
        {
            int t = s[i] - 'a';
            R[t]--;
            for(int j = 0; j < 26; j++)
            {
                if(L[j] > 0 && R[j] > 0)
                {
                    S.insert(26*t + j);
                }
            }
            L[t]++;
        }
        
        return S.size();
    }
};

















class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int ans = 0;
        int n = s.length();
        
        unordered_map<char, pair<int, int>> M;
        
        for (int i = 0; i < n; i++) {
            if (M.find(s[i]) == M.end()) {
                M[s[i]].first = i;
            }
            M[s[i]].second = i;
        }
        
        for (auto& [ch, positions] : M) {
            int left = positions.first;
            int right = positions.second;
            
            if (right - left <= 1) continue;  // No valid subsequences in this range
            
            unordered_set<char> uniqueChars;
            for (int i = left + 1; i < right; i++) {
                uniqueChars.insert(s[i]);
            }
            
            ans += uniqueChars.size();  // Count the unique characters between first and last occurrence
        }
        
        return ans;
    }
};
