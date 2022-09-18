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
    TreeNode* minNode(TreeNode* root){
        while(root->left){
            root = root->left;
        }
        
        return root;
    }
    
    TreeNode* del(TreeNode* root, int key){
        if(!root) return root;
        if(root->val == key){
            
            if(root->left and root->right){
                TreeNode* replace = minNode(root->right);
                root->val = replace->val;
                // cout<<replace->val<<"\n";
                root->right = del(root->right, root->val);                
            }
            else if(root->left){
                root = root->left;
            }
            else if(root->right){
                root = root->right;
            }
            else{
                 root = NULL; 
            } 
            return root;
        }
        else if(root->val > key)
            root->left = del(root->left, key);
        else
            root->right = del(root->right, key);
        return root;
    }
    
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        return del(root, key);
    }
};