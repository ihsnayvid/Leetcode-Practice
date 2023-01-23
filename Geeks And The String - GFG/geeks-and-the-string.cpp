//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string removePair(string s) {
        string ans = "";
        for(auto i: s){
            if(ans.empty() or ans.back() != i) ans.push_back(i);
            else{
                while(!ans.empty() and ans.back() == i) ans.pop_back();
            }
        }
        
        return ans.length() ? ans : "-1";
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s; 
        cin>>s;
        
        Solution obj;
        string res = obj.removePair(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends