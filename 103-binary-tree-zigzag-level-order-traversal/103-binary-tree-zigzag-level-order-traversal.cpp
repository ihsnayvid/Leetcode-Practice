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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        bool flag = true;
        int idx = 0;
        while(!q.empty()){
            int s = q.size();
            vector<int> level(s);
            for(int i=0; i<s; i++){
                auto curr = q.front();
                q.pop();
                                
                int idx = flag ? i : s - 1 - i;
                level[idx] = curr->val;
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            flag = !flag;
            ans.push_back(level);
        }
        return ans;    
    }
};