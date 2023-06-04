//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseEqn (string s)
    {
        int n = s.size();
        string ans = "";
        string num = "";
        for(int i=n-1; i>=0; i--){
            if(isdigit(s[i])){
                num += s[i];
            }
            else{
                reverse(num.begin(), num.end());
                ans += num;
                ans += s[i];
                num = "";
            }
        }
        reverse(num.begin(), num.end());
        ans += num;
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends