class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans = 1;
        for(int i=0; i<points.size(); i++){
            int x1 = points[i][0], y1 = points[i][1];
            unordered_map<double, int> mp;
            for(int j=i+1; j<points.size(); j++){
                int x2 = points[j][0], y2 = points[j][1];
                if(x1 == x2){
                    mp[INT_MAX]++;
                }
                else{
                    double slope = ((y2 - y1) * 1.0) / (x2 - x1);
                    mp[slope]++;
                }
            }
            for(auto i: mp){
                // cout<<i.first << " - " << i.second <<"\n";
                ans = max(ans, i.second + 1);
            }
            // cout<<"---\n";
        }
        
        return ans;    
    }
};