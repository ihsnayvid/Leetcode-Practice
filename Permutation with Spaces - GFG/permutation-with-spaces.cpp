// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    vector<string> ans;
    void solve(string s, string str){
        if(s.length() == 0){
            ans.push_back(str);
            return;
        }
        
        char ch = s[0];
        solve(s.substr(1,s.length()), str + " " + ch);
        solve(s.substr(1,s.length()), str + ch);
    }
    vector<string> permutation(string s){
        string str = "";
        str += s[0];
        s = s.substr(1,s.length());
        solve(s,str);
        return ans;
    }
};

// { Driver Code Starts.

int  main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        vector<string> ans;
        Solution obj;
        ans = obj.permutation(S);
        for(int i=0;i<ans.size();i++){
            cout<<"("<<ans[i]<<")";
        }
        cout << endl;
    }
}
  // } Driver Code Ends