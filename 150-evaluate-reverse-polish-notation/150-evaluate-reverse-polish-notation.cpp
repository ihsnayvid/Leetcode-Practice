class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto i:tokens){
            if(i == "+" || i == "-" || i == "*" || i == "/" ){
                int val1 = st.top();
                st.pop();
                int val2 = st.top();
                st.pop(); 
                int ans;
                switch(i[0]){
                    case '+' : ans = val2 + val1;                                
                                break;
                    case '-' : ans = val2 - val1;
                                break;
                    case '*' : ans = val2 * val1;
                                break;
                    case '/' : ans = val2 / val1;
                                break;
                }
                st.push(ans);
            }
            else
                st.push(stoi(i));             
        }
        return st.top();
    }
};