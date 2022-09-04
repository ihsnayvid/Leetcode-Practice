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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> mp;
        // idx level data
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int lvl = 0;
        mp[0][lvl].insert(root->val);
        while(!q.empty()){
            int s = q.size();
            while(s--){
                auto [curr, idx] = q.front();
                q.pop();
                if(curr->left) {
                    q.push({curr->left, idx - 1});
                    mp[idx - 1][lvl].insert(curr->left->val);
                }
                if(curr->right){
                    q.push({curr->right, idx + 1});
                    mp[idx + 1][lvl].insert(curr->right->val);
                }
            }
            lvl++;
        }
        
        
        vector<vector<int>> ans;
        for(auto i: mp){
            vector<int> t;
            for(auto j: i.second){
                for(auto s: j.second)
                    t.push_back(s);
            }
            ans.push_back(t);
        }
        return ans;
    }
};