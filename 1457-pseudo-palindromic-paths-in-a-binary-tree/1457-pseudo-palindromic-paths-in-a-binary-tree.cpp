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
private:
    int ans = 0;
    unordered_map<int, int> mp;
    
public:
    
    bool check(){
        int odd = 0;
        for(auto i: mp){
            if(i.second > 0){
                if(i.second & 1) odd ++;
            }
        }
        
        return (odd == 0 or odd == 1); 
    }
    
    void dfs(TreeNode* root){
        if(!root) return;
        mp[root->val]++;
        if(!root->left and !root->right){
            if(check()) ans++;
        }
        dfs(root->left);
        dfs(root->right);
        mp[root->val]--;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        dfs(root);
        return ans;
    }
};