class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> edge;
        vector<vector<int>> ans;                  // first: x, second: height
        for(auto b : buildings) {
            edge.push_back({b[0], -b[2]});
            edge.push_back({b[1], b[2]});
        }
        sort(edge.begin(), edge.end());                   // sort edge
        
        multiset<int> st = {0};
        int top = 0;                                        
        for(auto w : edge) {
            if(w.second < 0) st.insert(-w.second);
            else st.erase(st.find(w.second));
            
            if(*st.rbegin() != top){
                top = *st.rbegin();
                ans.push_back({w.first, top});
            }
        }        
        return ans;
    }
};