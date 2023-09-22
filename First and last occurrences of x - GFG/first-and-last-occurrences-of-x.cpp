//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    int firstOccurence(int *arr, int n, int x){
        int low = 0, high = n-1, ans = -1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(arr[mid] >= x){
                if(arr[mid] == x) ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
    int lastOccurence(int *arr, int n, int x){
        int low = 0, high = n-1, ans = -1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(arr[mid] <= x){
                if(arr[mid] == x) ans = mid;
                low = mid + 1;
            }
            else 
                high = mid - 1;
        }
        return ans;
    }
    vector<int> find(int arr[], int n , int x )
    {
        int first = firstOccurence(arr, n, x);
        int last = lastOccurence(arr, n, x);
        return {first, last};
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends