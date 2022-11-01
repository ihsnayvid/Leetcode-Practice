class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> ans;
        for(int i=0; i<grid[0].size(); i++){
            int pos = i, nextpos;
            for(int j=0; j<grid.size(); j++){
                nextpos = pos + grid[j][pos];
                if(nextpos < 0 or nextpos >= grid[0].size() or grid[j][pos] != grid[j][nextpos]){
                    pos = -1;
                    break;
                }
                pos = nextpos;
            }
            ans.push_back(pos);
        }
        return ans;
    }
};