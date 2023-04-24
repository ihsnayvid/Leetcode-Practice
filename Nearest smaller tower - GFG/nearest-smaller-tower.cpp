//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    vector<int> nearestSmallerTower(vector<int> arr)
    {
        int n = arr.size();
        stack<int> st;
        vector<int> rt(n, -1);
        for(int i=n-1; i>=0; i--){
            while(!st.empty() and arr[st.top()] >= arr[i]) st.pop();
            if(!st.empty()) rt[i] = st.top();
            st.push(i);
        }
        
        while(!st.empty()) st.pop();
        vector<int> lt(n, -1);
        for(int i=0; i<n; i++){
            while(!st.empty() and arr[st.top()] >= arr[i]) st.pop();
            if(!st.empty()) lt[i] = st.top();
            st.push(i);
        }
        vector<int> ans(n);
        for(int i=0; i<n; i++){
            // cout<<"<-"<<lt[i]<<" ->"<<rt[i]<<endl;
            if(rt[i] == -1) ans[i] = lt[i];
            else if(lt[i] == -1) ans[i] = rt[i];
            else{
                int dl = abs(lt[i]- i), dr = abs(rt[i]- i);
                if(dl == dr)
                    ans[i] = arr[lt[i]] <= arr[rt[i]] ? lt[i] : rt[i];
                else
                    ans[i] = dl < dr ? lt[i] : rt[i];
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution ob;
        vector<int> ans = ob.nearestSmallerTower(v);
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends