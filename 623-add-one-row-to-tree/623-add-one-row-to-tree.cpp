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
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(!root) return NULL;
        if(depth == 1){
            TreeNode * newnode = new TreeNode(val);
            newnode ->left = root;
            root = newnode;
            
        }
        else if(depth-1 == 1){
            TreeNode * leftnode = new TreeNode(val);
            TreeNode * rightnode = new TreeNode(val);
            leftnode->left = root->left;
            rightnode->right = root->right;
            
            root->left = leftnode;
            root->right = rightnode;
            return root;
        }
        root->left = addOneRow(root->left, val, depth-1);
        root->right = addOneRow(root->right, val, depth-1);
        return root;
    }
};