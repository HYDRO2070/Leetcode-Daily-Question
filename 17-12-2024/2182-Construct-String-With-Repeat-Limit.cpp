class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> index(26, 0);
        priority_queue<char> temp;
        string ans = "";
        int r = 0;
        for (char ch : s){
            index[ch - 'a']++;
            if(index[ch - 'a'] == 1){
                temp.push(ch);
            }
        }
        for (int i = 0; i < s.size(); i++) {
            if (index[temp.top() - 'a'] > 0 && r < repeatLimit) {
                ans += temp.top();
                index[temp.top() - 'a']--;
                r++;

            } else if (r == repeatLimit) {
                if (temp.size() == 1)
                    break;
                char ch = temp.top();
                temp.pop();
                ans += temp.top();
                index[temp.top() - 'a']--;
                if (index[temp.top() - 'a'] == 0) {
                    temp.pop();
                }
                r = 0;
                temp.push(ch);
            }
            if (index[temp.top() - 'a'] == 0) {
                temp.pop();
                r = 0;
            }
        }
        return ans;
    }
};
