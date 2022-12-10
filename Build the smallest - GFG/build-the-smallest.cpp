//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string buildLowestNumber(string num, int k);
// Driver program to test above function
int main()
{
    int t,n;
    string str;
    cin>>t;
    while(t--)
    {
    cin>>n;
    cin>>str;
    cout << buildLowestNumber(str, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends


string buildLowestNumber(string num, int k)
{
    stack<char> st;
    int n = num.length();
    st.push(num[0]);
    
    for(int i=1; i<n; i++){
        while(!st.empty() and st.top() > num[i] and k != 0){
            k--;
            st.pop();
        }
        st.push(num[i]);
    }
    
    string ans = "";
    while(!st.empty()){
        char c = st.top();
        st.pop();
        if(k <= 0)
            ans += c;
        else
            k--;
    }
    while(!ans.empty() and ans.back() == '0') ans.pop_back();
    if(ans.empty()) return "0";
    reverse(ans.begin(), ans.end());
    return ans;
}