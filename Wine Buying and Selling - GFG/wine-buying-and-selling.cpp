//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
#define lli long long int
class Solution{
  public:
  lli wineSelling(vector<int>& arr, int n){
        //Code here.
        lli total = 0, res = 0;
        for(int i = 0; i < n; i++){ 
            total += arr[i];
            res += abs(total);
        }
        return res;
    }
};



//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        long long int ans = ob.wineSelling(arr,n);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends