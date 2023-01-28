// { Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    int prec(char c){
        if(c == '+' or c == '-') return 1;
        else if(c == '*' or c == '/') return 2;
        else if(c == '^') return 3;
        else return 0;
    }
    string infixToPostfix(string s) {
        stack<char> st;
        string ans = "";
        
        for(auto i: s){
            if((i >= 'a' and i <= 'z') or (i >= 'A' and i <= 'Z')) ans += i;
            else if(i == '(') st.push(i);
            else if(i == ')'){
                while(!st.empty() and st.top() != '('){
                    ans += st.top();
                    st.pop();
                }
                if(!st.empty()) st.pop();
            }
            else{
                while(!st.empty() and prec(st.top()) >= prec(i)){
                    ans += st.top();
                    st.pop();
                }
                st.push(i);
            }
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        
        return ans;
    }
};


// { Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}
  // } Driver Code Ends