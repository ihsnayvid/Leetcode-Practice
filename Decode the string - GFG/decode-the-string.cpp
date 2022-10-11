//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string decodedString(string s){
        stack<char> st;
        int n = s.length();
        for(auto i: s){
            if(i != ']') st.push(i);
            else{
                string str = "";
                while(!st.empty() and st.top() != '['){
                    str = st.top() + str;
                    st.pop();
                }
                st.pop();
                
                string no = "";
                while(!st.empty() and isdigit(st.top())){
                    no = st.top() + no;
                    st.pop();
                }
                int num = stoi(no);
                      
                while(num--)
                    for(auto c: str)
                        st.push(c);    
            }
        }
                      
        string ans = "";
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}
// } Driver Code Ends