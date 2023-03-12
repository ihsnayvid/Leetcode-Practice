//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<int> findMaxRow(vector<vector<int>> mat, int n) {
        int mx = 0, row = 0;
        for(int i=0; i<n; i++){
            auto idx = upper_bound(mat[i].begin(), mat[i].end(), 0);
            if(idx == mat[i].end()) continue;
            
            int count = n - (idx - mat[i].begin());
            if(count > mx){
                mx = count;
                row = i;
            }
            
        }
        return {row, mx};
    }
};

//{ Driver Code Starts.

int main() {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<vector<int>> arr(n, vector<int> (n));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> arr[i][j];
        Solution obj;
        vector<int> ans = obj.findMaxRow(arr, n);
        for(int val : ans) {
            cout << val << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends