//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        vector<int> left(n, 0), right(n, 0);
        long long ans = 0;
        stack<int> st;
        for(int i=0; i<n; i++){
            while(!st.empty() and arr[st.top()] >= arr[i]) st.pop();
            left[i] = st.empty() ? 0 : st.top() + 1;
            st.push(i);
        }
        while(!st.empty()) st.pop();    //reuse stack
        for(int i=n-1; i>=0; i--){
            while(!st.empty() and arr[st.top()] >= arr[i]) st.pop();
            right[i] = st.empty() ? n-1 : st.top() - 1;
            st.push(i);
            ans = max(ans, arr[i] * (right[i] - left[i] + 1));
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends