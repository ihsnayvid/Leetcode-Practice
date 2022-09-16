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
    int preidx = 0;
    
    int search(vector<int> &in, int st, int en, int val){
        for(int i=st; i<=en; i++){
            if(in[i] == val) return i;
        }
        return -1;
    }
    
    TreeNode* create(vector<int> &pre, vector<int> &in, int st, int en){
        if(st <= en){
            TreeNode* root = new TreeNode(pre[preidx++]);
            int idx = search(in,st,en,root->val);
            
            root->left = create(pre, in, st, idx-1);
            root->right = create(pre, in, idx+1, en);
            
            return root;
        }
        return NULL;
    }
    
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
       return create(pre, in, 0, pre.size()-1); 
    }
};