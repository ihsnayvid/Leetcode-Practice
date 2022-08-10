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
    TreeNode* solve(vector<int> &v, int st, int en){
        if(st < en){
            int mid = st + (en-st) / 2;

            TreeNode* root = new TreeNode(v[mid]);
            root->left = solve(v, st, mid-1);
            root->right = solve(v, mid + 1, en);

            return root;
        }
        else if(st == en)
            return new TreeNode(v[st]);
        return NULL;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 1) return new TreeNode(nums[0]);
        
        return solve(nums, 0, nums.size() - 1);
    }
};