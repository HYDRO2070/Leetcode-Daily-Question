class Solution {
    // private:
    // bool isVowel(char c){
    //     return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    // }
public:
    // vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
    //     unordered_map<string,bool> valid;
    //     vector<int> prefix(words.size(),0);
    //     vector<int> res;
        
    //     for(string s : words){
    //         int n = s.size();
    //         if(isvowel(s[0]) && isvowel(s[n-1])){
    //              valid[s] = true;
    //         }
    //         else valid[s] = false;
    //     }
    //     if(valid[words[0]]) prefix[0] = 1;
    //     for(int i = 1;i < words.size();i++){
    //         prefix[i] = prefix[i-1];
    //         if(valid[words[i]]) prefix[i] += 1;
    //     }
    //     for(auto pair : queries){
    //         int ans = 0;
    //         ans += prefix[pair[1]] - prefix[pair[0]];
    //         if(valid[words[pair[0]]]) ans += 1;
    //         res.push_back(ans);
    //     }
    //     return res;
    // }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> prefix(n, 0);
        vector<bool> vowel(26,false);
        vowel[0] = true;
        vowel['e'-'a'] = true;
        vowel['i'-'a'] = true;
        vowel['o'-'a'] = true;
        vowel['u'-'a'] = true;
        
        for (int i = 0; i < n; ++i) {
            int wordSize = words[i].size();
            // if (isVowel(words[i][0]) && isVowel(words[i][wordSize - 1])) {
            if (vowel[words[i][0] - 'a'] && vowel[words[i][wordSize-1] - 'a']) {
                prefix[i] = 1;
            }
            if (i > 0) {
                prefix[i] += prefix[i - 1];
            }
        }
        
        vector<int> res;
        for (const auto& query : queries) {
            int left = query[0], right = query[1];
            int ans = prefix[right] - (left > 0 ? prefix[left - 1] : 0);
            res.push_back(ans);
        }
        
        return res;
    }
};
