//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int arr[], long long int n)  
    {
        int xornum = 0;
        vector<long long> ans(2, 0);
        for(int i=0; i<n; i++) xornum ^= arr[i];
        
        int rightset = xornum & ~(xornum - 1);
        
        for(int i=0; i<n; i++){
            ans[0] ^= rightset & arr[i] ? arr[i] : 0;
            ans[1] ^= rightset & arr[i] ? 0 : arr[i];
        }
        
        sort(ans.rbegin(), ans.rend());
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
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends