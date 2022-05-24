class Solution {
public:
    
    /*
            0   1   2   3   4   5
            )   (   )   (   )   )
    st:     5      
    
    
    ans = 4
    */
    
    int longestValidParentheses(string s) {
        stack<int> st;
        int ans = 0;
        st.push(-1);
        
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(') st.push(i);
            else{
                st.pop();
                if(st.empty()) st.push(i);
                else ans = max(ans, i - st.top());
            }
        }
        return ans;
    }
};