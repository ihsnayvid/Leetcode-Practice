class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for(auto i:s){
            if(i == '(' or i == '{' or i == '['){
                st.push(i);
            }
            else{
                if(i == ')'){
                    if(!st.empty() and st.top() != '(') return false;
                    else if(st.empty()) return false;
                    else st.pop();
                }
                if(i == ']'){
                    if(!st.empty() and st.top() != '[') return false;
                    else if(st.empty()) return false;
                    else st.pop();
                }
                if(i == '}'){
                    if(!st.empty() and st.top() != '{') return false;
                    else if(st.empty()) return false;
                    else st.pop();
                }
            }
        }
        return st.empty();
    }
};