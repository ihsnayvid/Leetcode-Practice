//{ Driver Code Starts
//Initial Template for CPP

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    long long maxTripletProduct(long long arr[], int n)
    {
    	if(n == 3) return arr[0] * arr[1] * arr[2];
    	sort(arr, arr+n);
    	long long a = INT_MIN, b = INT_MIN;
    	if(arr[0] < 0 and arr[1] < 0){
    	    a = arr[0] * arr[1] * arr[n-1];
    	}
    	b = arr[n-1] * arr[n-2] * arr[n-3];
    	return max(a, b);
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,i;
	    cin>>n; long long arr[n];
	    for(i=0;i<n;i++)
	    cin>>arr[i];
	    Solution ob;
	    cout <<ob.maxTripletProduct(arr, n);
	    cout<<"\n";
	}
    return 0;
}
// } Driver Code Ends