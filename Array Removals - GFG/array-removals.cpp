//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    //0 1 2 3 4
    //1 2 5 6 8 
    //i
    //    j
    int removals(vector<int>& arr, int k){
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int i = 0, j = 0, mx = 0;
        while(j < n){
            int diff = arr[j] - arr[i];
            
            if(diff <= k){
                mx = max(mx, (j-i+1));
                j++;
            }
            else{
                while(diff > k){
                    i++;
                    diff = arr[j] - arr[i];
                }
            }
        }
        
        return n - mx;
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution ob;
        int ans = ob.removals(arr,k);
        
        cout<<ans<<endl;
    }
}



// } Driver Code Ends