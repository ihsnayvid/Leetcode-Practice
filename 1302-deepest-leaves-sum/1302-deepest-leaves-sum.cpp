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
    int height (TreeNode* root){
        if(!root) return 0;
        return max(height(root->left), height(root->right)) + 1;
    }
    int sum = 0;
    int sumLevel(TreeNode* root, int k){        
        if(!root)
            return sum;
        if(k == 0)
            sum = sum + root->val;
        sumLevel(root->left, k - 1);
        sumLevel(root->right, k - 1);
        return sum;
    }
    
    int deepestLeavesSum(TreeNode* root) {
        int h = height(root);
        int sum = sumLevel(root, h - 1);
        return sum;
    }};