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
    bool solve(TreeNode *left, TreeNode *right, int k){
        if(!left or !right) return false;
        
        int sum = left->val + right->val;
        if(left == right and sum == k)  return solve(left->left, right->right, k);
        
        if(sum == k) return true;
        else if(sum < k)
            return solve(left->right, right, k) or solve(left, right->right, k);
        else
            return solve(left->left, right, k) or solve(left, right->left, k);
    }
    
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        return solve(root, root, k);
    }
};