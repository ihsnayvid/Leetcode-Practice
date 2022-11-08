class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        for(auto i: s){
            if(st.empty()) st.push(i);
            else{
                if((isupper(st.top()) and tolower(st.top()) == i) or (islower(st.top()) and toupper(st.top()) == i))
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