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
    int preIndex = 0;
    int search(vector<int> inorder, int st, int en, int target){        
        for(int i=st; i<=en; i++){
            if(inorder[i] == target) return i;
        }
        return -1;
    }
    
    TreeNode* createTree(vector<int> &pre, vector<int>& in, int st, int en){
        if(st > en) return NULL;
        TreeNode* root = new TreeNode(pre[preIndex++]);
        int inIndex = search(in,st,en, root->val);
        
        root->left = createTree(pre,in,st,inIndex-1);
        root->right = createTree(pre,in,inIndex+1,en);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        return createTree(preorder, inorder, 0, n-1);       
    }
};