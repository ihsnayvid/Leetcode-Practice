class Solution {
public:
    vector<int> avoidFlood(vector<int>& r) {
        int n = r.size();
        vector<int> ans(n, -1);
        
        unordered_map<int, int> lastrain;
        set<int> st;    //dry days
            
        for(int i=0; i<n; i++){
            if(r[i] == 0) st.insert(i);
            else{
                if(!lastrain.count(r[i])) lastrain[r[i]] = i;
                else{
                    int prev = lastrain[r[i]];
                    lastrain[r[i]] = i;
                    auto idx = st.upper_bound(prev);
                    if(idx == st.end()) return {};
                    ans[*idx] = r[i];
                    st.erase(*idx);
                }
            }
        }
        
        for(int i=0; i<n; i++){
            if(r[i] == 0 and ans[i] == -1) ans[i] = 1;
        }
        return ans;
    }
};