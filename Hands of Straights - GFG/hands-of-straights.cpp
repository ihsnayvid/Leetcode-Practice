//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isStraightHand(int n, int k, vector<int> &hand) {
        if(n % k != 0) return false;
        if(k == 1) return true;
        multiset<int> st(hand.begin(), hand.end());
        while(!st.empty()){
            int curr = *st.begin();
            for(int i=0; i<k; i++){
                auto itr = st.find(curr);
                if(itr == st.end()) return false;
                st.erase(itr);
                curr++;
            }
        }
        return true;
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