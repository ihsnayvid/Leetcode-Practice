//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    
    int shortestDistance(int n, int m, vector<vector<int>> a, int st, int en) {
        queue<pair<int, int>> q;
        q.push({0, 0});
        a[0][0] = 2;
        
        int steps = 0;
        while(!q.empty()){
            int s = q.size();
            while(s--){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                
                if(x == st and y == en) return steps;
                
                for(int i=0; i<4; i++){
                    int nx = x + dx[i], ny = y + dy[i];
                    if(nx < 0 or ny < 0 or nx >= n or ny >= m or a[nx][ny] != 1) continue;
                    q.push({nx, ny});
                    a[nx][ny] = 2;
                }
            }
            steps++;
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends