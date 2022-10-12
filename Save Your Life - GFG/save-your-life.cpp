//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    unordered_map<char, int> mp;
    
    int ascii(char c){
        return mp.count(c) ? mp[c] : (int) c;
    }  
        
    string maxSum(string w, char x[], int b[],int n){
        for(int i=0; i<n; i++)
            mp[x[i]] = b[i];
        
        int curr = 0, mx = INT_MIN, i = 0, j = 0, st = 0, en = 0;
        while(j<w.size()){
            curr += ascii(w[j]);
            if(curr > mx){
                mx = curr;
                st = i;
                en = j;
            }
            if(curr < 0){
                curr = 0;
                i = j+1;
            }
            j++;
        }
        return w.substr(st, en-st+1);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string w;
        cin>>w;
        int n;
        cin>>n;
        char x[n];
        int b[n];
        for(int i = 0;i<n;i++)
            cin>>x[i];
        for(int i = 0;i<n;i++)
            cin>>b[i];
        Solution ob;
        cout << ob.maxSum(w,x,b,n) << endl;
    }
    return 0; 
}
// } Driver Code Ends