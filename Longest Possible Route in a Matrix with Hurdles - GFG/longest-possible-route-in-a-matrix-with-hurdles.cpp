// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
    int ans;
    bool check;
    
public:
    
    int solve(vector<vector<int>> mat, int n, int m, int xs, int ys, int xd, int yd){
        if(xs<0 or xs>n-1 or ys<0 or ys>m-1 or mat[xs][ys] == 0 or mat[xs][ys] == -1)
            return INT_MIN;
        
        if(xs == xd and ys == yd){
            check = true;
            return 1;
        }
        
        mat[xs][ys] = -1;
        
        int u = 1 + solve(mat, n, m, xs-1, ys, xd, yd);
        int r = 1 + solve(mat, n, m, xs, ys+1, xd, yd);
        int d = 1 + solve(mat, n, m, xs+1, ys, xd, yd);
        int l = 1 + solve(mat, n, m, xs, ys-1, xd, yd);
        
        mat[xs][ys] = 1;
        
        ans = max(u,max(r,max(d,l)));
        
        return ans;
    }
    int longestPath(vector<vector<int>> mat, int xs, int ys, int xd, int yd)
    {
        if(mat[xs][ys] == 0 or mat[xd][yd] == 0) return -1;
        
        ans = -1;
        check = false;
        solve(mat, mat.size(), mat[0].size(), xs, ys, xd, yd);
        
        return check ? ans - 1: -1;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int xs, ys, xd, yd;
        cin >> xs >> ys >> xd >> yd;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
        }
        Solution ob;
        int ans = ob.longestPath(mat, xs, ys, xd, yd);
        cout << ans;
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends