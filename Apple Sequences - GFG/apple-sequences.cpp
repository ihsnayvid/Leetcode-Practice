//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:

    int appleSequences(int n, int m, string arr){
        int count = 0, i = 0, ans = INT_MIN;
        for(int j=0; j<n; j++){
            if(arr[j] == 'O') count++;
            while(count > m){
                if(arr[i] == 'O') count--;
                i++;
            }
            ans = max(ans, j-i+1);
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
        int N, M;
        cin >> N >> M;
        string arr;
        cin >> arr;
        
        Solution ob;
        cout << ob.appleSequences(N, M, arr) << endl;
    }
    return 0; 
} 
// } Driver Code Ends