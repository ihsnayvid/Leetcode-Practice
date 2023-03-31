//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
        vector <int> lexicographicallyLargest(vector <int> &a,int n)
        {
            vector<int> ans;
            priority_queue<int> pq;
            pq.push(a[0]);
            for(int i=1; i<n; i++){
                if((a[i] + a[i-1]) % 2 == 0) pq.push(a[i]);
                else{
                    while(!pq.empty()){
                        ans.push_back(pq.top());
                        pq.pop();
                    }
                    pq.push(a[i]);
                }
            }
            while(!pq.empty()){
                ans.push_back(pq.top());
                pq.pop();
            }
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
        int n;
        cin>>n;
        vector <int> a(n);
        for(auto &j:a)
            cin>>j;
        Solution s;
        vector <int> b=s.lexicographicallyLargest(a,n);
        for(auto i:b)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends