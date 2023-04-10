//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxIntersections(vector<vector<int>> lines, int n) {
        // sort(lines.begin(), lines.end());
        map<int, int> mp;
        
        for(auto &l : lines){
            mp[l[0]]++;
            mp[l[1]+1]--;
        }
        
        int ans = 0, pre = 0;
        for(auto &i: mp){
            pre += i.second;
            ans = max(ans, pre);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> mat(N, vector<int>(2));
        for (int j = 0; j < 2; j++) {
            for (int i = 0; i < N; i++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        cout << obj.maxIntersections(mat, N) << endl;
    }
}
// } Driver Code Ends