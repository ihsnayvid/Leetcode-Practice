//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};
    
    void dfs(int x, int y, int n, int m, int color, int newcolor, vector<vector<int>> &vis, vector<vector<int>>& image){
        if(x < 0 or y < 0 or x >= n or y >= m or vis[x][y] or image[x][y] != color) return;
        vis[x][y] = 1;
        image[x][y] = newcolor;
        for(int i=0; i<4; i++){
            dfs(x + dx[i], y + dy[i], n, m, color, newcolor, vis, image);
        }
    }


    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newcolor) {
        int n = image.size(), m = image[0].size();
        int color = image[sr][sc];
        vector<vector<int>> vis(n, vector<int>(m, 0));
        // vis[sr][sc] = 1;
        // image[sr][sc] = newcolor;
        // for(int i=sr; i<n; i++){
        //     for(int j=sc; j<m; j++){
        //         if(image[i][j] == color and !vis[i][j]){
                    dfs(sr, sc, n, m, color, newcolor, vis, image);
        //         }
        //     }
        // }
        
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends