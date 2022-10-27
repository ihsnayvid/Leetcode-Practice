//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> leafNodes(int arr[],int n) {
        vector<int> ans;
        int root = arr[0];
        stack<int> st;
        st.push(root);
        
        for(int i=1; i<n; i++){
            if(arr[i] < st.top()) st.push(arr[i]);
            else{
                int val = st.top(), count = 0;
                while(!st.empty() and st.top() < arr[i]){
                    count ++;
                    st.pop();
                }
                st.push(arr[i]);
                if(count > 1) ans.push_back(val);
            }
        }
        ans.push_back(st.top());
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
        int N;
        cin >> N;
        int arr[N];
        for(int i=0;i<N;i++)cin>>arr[i];
        Solution ob;
        vector<int>ans=ob.leafNodes(arr,N);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends