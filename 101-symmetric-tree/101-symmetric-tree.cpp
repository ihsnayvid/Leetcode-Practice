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
    bool check(TreeNode* t1, TreeNode* t2){
        if(!t1 and !t2) return true;
        else if(!t1 or !t2) return false;
        
        return t1->val == t2->val and check(t1->left, t2->right) and check(t1->right, t2->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        
        return check(root->left, root->right);
        
    }
};