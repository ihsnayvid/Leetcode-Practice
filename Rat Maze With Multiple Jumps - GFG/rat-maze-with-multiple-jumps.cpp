// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:

    bool solve(vector<vector<int>> m, vector<vector<int>> &ans, int i, int j, int n){
        if(i == n-1 and j == n-1){
            ans[i][j] = 1;
            return true;
        }
        
        if(i<0 or j<0 or i>n-1 or j>n-1 or m[i][j] == 0) return false;
        
        ans[i][j] = 1;
        for(int x=1; x<=m[i][j]; x++){
            if(solve(m, ans, i, j+x, n)) return true;
            if(solve(m, ans, i+x, j, n)) return true;
            
        }
        ans[i][j] = 0;
        
        return false;
    }

    vector<vector<int>> ShortestDistance(vector<vector<int>>&matrix){
        int n = matrix.size();
        vector<vector<int>> ans(n,vector<int>(n,0));
        if(solve(matrix,ans,0,0,n))
            return ans;
        return {{-1}};
	        
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.ShortestDistance(matrix);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends