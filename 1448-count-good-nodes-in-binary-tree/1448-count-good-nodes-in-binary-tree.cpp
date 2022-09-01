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
    int count = 0;
    int goodNodes(TreeNode* root, int mx = INT_MIN) {
        if(!root) return 0;
        
        if(root->val >= mx){
            count ++;
            mx = root->val;
        }
        
        goodNodes(root->left, mx);
        goodNodes(root->right, mx);
        
        return count;
    }
};