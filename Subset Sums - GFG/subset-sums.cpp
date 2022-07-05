// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    vector<int> ans;
    
    void solve(int ind, vector<int> ds, int sum, vector<int> arr, int n){
        if(ind == n){
            ans.push_back(sum);
            return;
        }
        
        ds.push_back(arr[ind]);
        solve(ind+1, ds, sum + arr[ind], arr, n);
        ds.pop_back();
        solve(ind+1, ds, sum, arr, n);
        
    }
    
    vector<int> subsetSums(vector<int> arr, int n)
    {
        vector<int> ds;
        solve(0,ds,0,arr,n);
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends