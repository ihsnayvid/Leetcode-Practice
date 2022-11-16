//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    int beauty(vector<int> v){
        int mx = INT_MIN, mn = INT_MAX;
        for(auto i: v){
            if(i != 0){
                mx = max(mx, i);
                mn = min(mn, i);
            }
        }
        return mx - mn;
    }
  
    int beautySum(string s) {
        int ans = 0;
        for(int i=0; i<s.length(); i++){
            vector<int> v(26, 0);
            for(int j = i; j<s.length(); j++){
                v[s[j] - 'a']++;
                ans += beauty(v);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.beautySum(s) << endl;
    }
    return 0;
}
// } Driver Code Ends