// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int findTime(string s1, string s2) {
        int i = 0, ans = 0;
        int l = s2.length();
        unordered_map<char,int> mp;
        
        for(auto x:s1){
            mp[x] = i;
            i++;
        }
        int curr = 0;
        for(int j = 0; j < l; j++){
            ans += abs(curr - mp[s2[j]]);
            curr = mp[s2[j]];
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S1,S2;
        cin>>S1;
        cin>>S2;

        Solution ob;
        cout<<ob.findTime(S1,S2)<<endl;
    }
    return 0;
}  // } Driver Code Ends