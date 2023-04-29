//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    long long findNumber(long long n){
        vector<int> arr = {9,1,3,5,7,9};
        vector<int> ans;
        
        while(n){
            int rem = n % 5;
            if(rem == 0) n--;
            ans.push_back(arr[rem%5]);
            n /= 5;
        }
        long long num = 0;
        for(int i=ans.size()-1; i>=0; i--){
            num = num*10 + ans[i];
        }
        return num;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long N;
        cin>>N;
        Solution ob;
        cout<<ob.findNumber(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends