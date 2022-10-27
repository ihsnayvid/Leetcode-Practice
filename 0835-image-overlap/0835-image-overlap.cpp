class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size(), ans = 0;
        vector<pair<int, int>> vp1, vp2;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(img1[i][j] == 1) vp1.push_back({i, j});
                if(img2[i][j] == 1) vp2.push_back({i, j});
            }
        }
        
        map<pair<int, int>, int> mp;
        
        for(auto i: vp1){
            for(auto j: vp2){
                int x = i.first - j.first;
                int y = i.second - j.second;
                mp[{x, y}]++;
                ans = max(ans, mp[{x, y}]);
            }
        }
        return ans;
    }
};