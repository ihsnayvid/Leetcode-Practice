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
public:
    int ans = 1e5+1;
    
    void solve(TreeNode* root, int lvl){
        if(!root) return;
        if(!root->left and !root->right){
            ans = min(ans, lvl);
        }
        
        solve(root->left, lvl + 1);
        solve(root->right, lvl + 1);
    }
    
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        solve(root, 1);
        return ans;
    }
};