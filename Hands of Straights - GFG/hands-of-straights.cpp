//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isStraightHand(int n, int k, vector<int> &hand) {
        if(n % k != 0) return false;
        if(k == 1) return true;
        sort(hand.begin(), hand.end());
        vector<int> vis(n, 0);
        int g = 0, count = 0, currSize = 0, prev = 0;
        for(int i = 0; i < n; i++){
            if(vis[i]) continue;
            vis[i] = 1;
            currSize = 1;
            prev = hand[i];
            for(int j=i+1; j<n; j++){
                if(hand[j] == prev + 1){
                    vis[j] = 1;
                    prev = hand[j];
                    currSize++;
                }
                
                if(currSize == k){
                    g++;
                    break;
                }
            }
        }
        return g == (n/k);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, groupSize;
        cin >> N >> groupSize;

        vector<int> hand(N);
        for (int i = 0; i < N; i++) cin >> hand[i];

        Solution obj;
        int ans = obj.isStraightHand(N, groupSize, hand);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends