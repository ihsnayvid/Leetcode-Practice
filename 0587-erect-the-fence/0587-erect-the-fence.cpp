class Solution {
public:
    int getRotationAngle(vector<int> A, vector<int> B, vector<int> C) {
        return ((B[0] - A[0]) * (C[1] - A[1])) - ((B[1] - A[1]) * (C[0] - A[0]));
    }   
    
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        if (trees.size() <= 3) return trees;
        sort(trees.begin(), trees.end());
        
		// Upper hull construction
        vector<vector<int>> left;
        left.push_back(trees[0]);
        left.push_back(trees[1]);
        for (int i = 2; i < trees.size(); i++) {
            int ls = left.size();
            while (left.size() >= 2 and getRotationAngle(left[ls-2], left[ls-1], trees[i]) > 0) {
                left.pop_back();
                ls--;
            }
            left.push_back(trees[i]);
        }
        
		// Lower hull construction
        vector<vector<int>> right;
        right.push_back(trees[trees.size() - 1]);
        right.push_back(trees[trees.size() - 2]);
        for (int i = trees.size() - 3; i >= 0; --i) {
            int rs = right.size(); 
            while (right.size() >= 2 and getRotationAngle(right[rs-2], right[rs-1], trees[i]) > 0) {
                right.pop_back();
                rs--;
            }
            right.push_back(trees[i]);
        }
        
		// Pop the last elements as they would've occurred in both lists
        right.pop_back();
        left.pop_back();
        for (int i = 0; i < right.size(); i++) {
            left.push_back(right[i]);
        }
        
		// Sort and remove duplicate elements
        sort(left.begin(), left.end());
        left.erase(std::unique(left.begin(), left.end()), left.end());
        
        return left;
    }
};