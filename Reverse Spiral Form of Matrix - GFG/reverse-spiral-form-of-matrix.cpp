//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> reverseSpiral(int r, int c, vector<vector<int>>&a)  {
        int rs=0,cs=0,re=r-1,ce=c-1;
        vector<int> ans;
        while(rs<=re and cs<=ce){
            for(int col=cs;col<=ce;col++) ans.push_back(a[rs][col]);
            rs++;
            for(int row=rs;row<=re;row++) ans.push_back(a[row][ce]);
            ce--;
            
            if(rs<=re)
                for(int col=ce;col>=cs;col--) ans.push_back(a[re][col]);
            re--;            
            
            if(cs<=ce)
                for(int row=re;row>=rs;row--) ans.push_back(a[row][cs]);
            cs++;            
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin>>R>>C;
        vector<vector<int>> a(R, vector<int>(C, 0));
        for(int i = 0;i < R*C;i++)
            cin>>a[i/C][i%C];
        Solution ob;
        vector<int>ans=ob.reverseSpiral(R,C,a);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
            cout<<endl;
    }
    return 0;
}

// } Driver Code Ends