//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        int mod = 1e5;
        vector<int> dist(100000, INT_MAX);
        queue<pair<int, int>> q;
        dist[start] = 0;
        q.push({start, 0});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            
            int curr = it.first, moves = it.second;
            for(auto i: arr){
                int num = (i * curr) % mod;
                if(moves + 1 < dist[num]){
                    dist[num] = moves + 1;
                    if(num == end) return moves + 1;
                    q.push({num, dist[num]});
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends