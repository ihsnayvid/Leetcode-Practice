class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int i=0,l=tokens.size();
        stack<int> st;
        while(i<l){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/" ){
                int val1 = st.top();
                st.pop();
                int val2 = st.top();
                st.pop();
                //cout<<val1<<" "<<val2<<endl;
                switch(tokens[i][0]){
                    case '+' : st.push(val2 + val1);
                                //cout<<st.top()<<endl;
                                break;
                    case '-' : st.push(val2 - val1);
                                break;
                    case '*' : st.push(val2 * val1);
                                break;
                    case '/' : st.push(val2 / val1);
                                //cout<<st.top()<<endl;
                                break;
                }
            }
            else{
                int dig = stoi(tokens[i]);
                st.push(dig); 
            }
            i++;
        }
        return st.top();
    }
};