//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    
    // int check(string s){
    //     int lower = 0, upper = 0;
    //     for(auto &i: s){
    //         if(islower(i)) lower++;
    //         else if(isupper(i)) upper++;
    //     }
    //     return lower == upper;
    // }
    int countSubstring(string s)
    {
        int ans = 0, n = s.size();
        for(int i=0; i<n; i++){
            int lower = 0, upper = 0;
            for(int j=i; j<n; j++){
                if(islower(s[j])) lower++;
                else if(isupper(s[j])) upper++;
                if(lower == upper) ans++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
        cout<<obj.countSubstring(S)<<endl;
    }
}  
// } Driver Code Ends