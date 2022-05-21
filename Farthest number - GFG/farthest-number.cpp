// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution{   
  public:
    vector<int> farNumber(int n,vector<int> arr){
        // BRUTE FORCE
        // vector<int> v(n,-1);
        // for(int i=0; i<n; i++){
        //     for(int j=n-1; j>i; j--){
        //         if(arr[j] < arr[i]){
        //             v[i] = j;
        //             break;
        //         }
        //     }
        // }
        // return v;
        
        // 0    1   2   3   4   -->index
        // 3    1   5   2   4   -->arr
        // 1    1   2   2   4   -->min elt subarray
        
        vector<int> suff(n);
        suff[n-1] = arr[n-1];
        for(int i=n-2; i>=0; i--)
            suff[i] = min(suff[i+1], arr[i]);
        
        for(int i=0; i<n; i++){
            int low = i+1, high = n-1, ans = -1;
            while(low <= high){
                int mid = (low + high) >> 1;
                if(suff[mid] < arr[i]){
                    ans = mid;
                    low = mid + 1;
                }
                else
                    high = mid - 1;
            }
            arr[i] = ans;
        }
        return arr;
    }
};

// { Driver Code Starts.
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        vector<int> Arr(N);
        for(int i=0;i<N;i++)
            cin>>Arr[i];
        Solution obj;
        vector<int> answer=obj.farNumber(N,Arr);
        for(auto i:answer)
            cout<<i<<" ";
        cout<<endl;
  }
}  // } Driver Code Ends