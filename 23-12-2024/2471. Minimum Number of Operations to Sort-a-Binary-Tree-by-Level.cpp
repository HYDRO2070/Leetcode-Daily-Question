/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    private:
    int sortnums(vector<int> &nums){
        int n = nums.size();
        int ans = 0;
        for(int i = 0;i < n-1;i++){
            int sm = i+1;
            for(int j = i+2;j < n;j++){
                if(nums[sm] > nums[j]){
                    sm = j;
                }
            }
            if(nums[i] > nums[sm]){
                swap(nums[i],nums[sm]);
                ans++;
            }

        }
        return ans;
    }
public:
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        int ans = 0;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> nums;
            for(int i = 0;i < size;i++){
                auto temp = q.front();
                q.pop();
                nums.push_back(temp->val);
                if(temp->left)
                q.push(temp->left);
                if(temp->right)
                q.push(temp->right);
            }
            if(nums.size() != 1)
            ans += sortnums(nums);
        }
        return ans;
    }
};
