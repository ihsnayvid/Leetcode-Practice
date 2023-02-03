//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    // down 
    pair<int,int> endPoints(vector<vector<int>> matrix, int r, int c){
        pair<int, int> ans;
        int k = 0, i = 0, j = 0;
        while(i >= 0 and j >= 0 and i < r and j < c){
            ans = {i, j};
            if(matrix[i][j] == 1){
                k = (k + 1) % 4;
                matrix[i][j] = 0;
            }
            i += dx[k];
            j += dy[k];
        }
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix, row, col);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}
// } Driver Code Ends