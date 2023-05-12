//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int arrayOperations(int n, vector<int> &arr) {
        int i = 0, j = 0, op = 0, curr = 0, z = 0;
        bool found = false;
        for(int i=0; i<=n; i++){
            if(i == n and curr != 0){
                op++;
            }
            else{
                if(arr[i] != 0){
                    curr++;
                }
                else{
                    found = true;
                    z++;
                    if(curr != 0){
                        curr = 0;
                        op++;
                    }
                } 
            }
            
        }
        if(!found) return -1;
        if(z == n) return 0;
        return op;
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
        
        Solution obj;
        int res = obj.arrayOperations(n, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends