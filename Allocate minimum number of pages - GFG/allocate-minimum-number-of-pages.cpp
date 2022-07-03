// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    
    bool check(int a[], int n, int m, int mid){
        int stu = 1, sum = 0;
        for(int i=0; i<n; i++){
            sum += a[i];
            if(sum > mid){
                stu++;
                sum = a[i];
            }
            if(stu > m) return false;
        }
        return true;
    }
    
    //Function to find minimum number of pages.
    int findPages(int a[], int n, int m) 
    {
        int low = 0, high = 0;
        for(int i=0; i<n; i++){
            high += a[i];
            if(a[i] > low) low = a[i];
        }
        
        int ans = -1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(check(a,n,m,mid)){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends