class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& v) {
        vector<vector<int>>ans;
        for(auto &i: intervals){
            if(i[1] < v[0]) ans.push_back(i);
            else if(v[1] < i[0]){
                ans.push_back(v);
                v = i;
            }
            else{
                v[0] = min(v[0], i[0]);
                v[1] = max(v[1], i[1]);
            }    
        }
        
        ans.push_back(v);
        return ans;
    }
};