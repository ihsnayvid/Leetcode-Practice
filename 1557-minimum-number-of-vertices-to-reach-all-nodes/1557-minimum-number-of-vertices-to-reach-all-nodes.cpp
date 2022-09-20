class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        unordered_set<int> st;
        for(auto i: edges)
            st.insert(i[1]);
        
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(st.count(i)>0) continue;
            ans.push_back(i);
        }
        return ans;    
    }
};