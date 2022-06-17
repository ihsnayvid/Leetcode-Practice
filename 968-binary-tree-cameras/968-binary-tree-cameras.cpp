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
    
    int solve(TreeNode *root, int &cam){
        if(!root) return 1;
        
        int left = solve(root->left, cam);
        int right = solve(root->right, cam);
        
        if(left == 0 or right == 0){
            cam++;
            return 2;
        }
        else if(left == 2 or right == 2) return 1;
                
        return 0;
    }
    
    
    int minCameraCover(TreeNode* root) {
        int cam = 0;
        int ans = solve(root, cam);
        
        if(ans == 0) cam ++;
        
        return cam;
    }
};