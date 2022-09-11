class Solution {
public:
    int partitionString(string s) {
        int n = s.length(), j = 0,ans = 0;
        unordered_set<char> st;
        
        for(int j=0; j<n; j++){
            if(st.count(s[j]) > 0){
                st.clear();
                ans++;
            }
            st.insert(s[j]);
        }
        
        return ans+1;
    }
};