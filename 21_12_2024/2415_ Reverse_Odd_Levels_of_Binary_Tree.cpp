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
    void reversenode(vector<TreeNode*> &arr){
        int n = arr.size()-1;
        for(int i = 0;i <= (n/2);i++){
            int temp = arr[n-i]->val;
            arr[n-i]->val = arr[i]->val;
            arr[i]->val = temp;
        }
    }
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        vector<TreeNode*> arr;
        int lvl = 0;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            if(q.front() == NULL){
                q.pop();
                if(lvl&1){
                    reversenode(arr);
                    arr.clear();
                }
                if(q.size() > 1)
                q.push(NULL);
                else break;
                lvl++;
            }
            auto temp = q.front();
            q.pop();
            if(lvl%2 != 0)
            arr.push_back(temp);
            if(temp->left || temp->right){
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        return root;
    }
};
