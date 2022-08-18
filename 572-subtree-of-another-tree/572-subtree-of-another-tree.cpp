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
    bool isSameTree(TreeNode *p, TreeNode *q){
        if(!p or !q) return p == q;
        bool node = p->val == q->val;
        bool left = isSameTree(p->left, q->left);
        bool right = isSameTree(p->right, q->right);
        return node and left and right;
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false;
        bool node = false;
        if(root->val == subRoot->val)
            node += isSameTree(root, subRoot);
        
        node += isSubtree(root->right, subRoot);
        node += isSubtree(root->left, subRoot);

        return node;
    }
};