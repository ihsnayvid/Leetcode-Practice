//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

//Back-end complete function Template for C++

class Solution{
    public:
    unordered_map<string, bool> mp;
    bool solve(string a, string b){
        int n = a.size();
        if(a == b) return true;
        if(n <= 1) return false;
        string key = a + "|" + b;
        if(mp.find(key) != mp.end()) return mp[key];
        
        for(int i=1; i<n; i++){
            bool check1 = solve(a.substr(0, i), b.substr(0, i)) and solve(a.substr(i, n-i), b.substr(i, n-i));
            bool check2 = solve(a.substr(0, i), b.substr(n-i, i)) and solve(a.substr(i, n-i), b.substr(0, n-i));
            
            if(check1 or check2)
                return mp[key] = true;
        }
        return mp[key] = false;
    }
    bool isScramble(string a, string b){
        return solve(a, b);
    }    
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        string S1, S2;
        cin>>S1>>S2;
        Solution ob;
        
        if (ob.isScramble(S1, S2)) {
            cout << "Yes";
        }
        else {
            cout << "No";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends