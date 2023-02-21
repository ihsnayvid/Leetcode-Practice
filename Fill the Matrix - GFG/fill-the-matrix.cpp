//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    
    int minIteration(int n, int m, int x, int y){    
        int ans = 0, filled = 1;
        x--, y--;
        queue<pair<int, int>> q;
        vector<vector<int>> vis(n, vector<int> (m, 0));
        q.push({x, y});
        vis[x][y] = 1;
        while(!q.empty()){
            int s = q.size(); 
            while(s--){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                
                // if(filled == n*m) return ans;
                for(int k=0; k<4; k++){
                    int nx = i + dx[k], ny = j + dy[k];
                    if(nx < 0 or ny < 0 or nx >= n or ny >= m or vis[nx][ny]) continue;
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                    // filled++;
                }
            }
            // cout<<filled<<"\n";
            if(!q.empty()) ans++;
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
        int N, M, x, y;
        cin >> N >> M;
        cin >> x >> y;
        
        Solution ob;
        cout << ob.minIteration(N, M, x, y) << endl;
    }
    return 0; 
} 
// } Driver Code Ends