class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        for(auto i: s){
            if(st.empty()) st.push(i);
            else{
                if(st.top() == i + 32 or st.top() == i - 32)
                    st.pop();
                else
                    st.push(i);
            }
        }
        s = "";
        while(!st.empty()){
            s = st.top() + s;
            st.pop();
        }
        return s;
    }
};