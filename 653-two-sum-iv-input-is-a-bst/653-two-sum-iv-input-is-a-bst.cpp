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
    vector<int> in;
    void store(TreeNode* root){
        if(!root) return;
        store(root->left);
        in.push_back(root->val);
        store(root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        store(root);
        int i = 0, j = in.size() - 1;
        while(i<j){
            if(in[i] + in[j] == k) return true;
            else if(in[i] + in[j] > k) j--;
            else i++;
        }
        return false;
    }
};