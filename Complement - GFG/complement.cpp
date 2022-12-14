//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findRange(string str, int n) {
        int l = 0, r = 0, ans = INT_MIN;
        int i = 0, j = 0, curr = 0;
        vector<int> lr(2);
        for(int i=0; i<n; i++){
            int d = str[i] == '0' ? 1 : -1;
            if(d > d + curr){
                l = i;
                r = i;
                curr = d;
            }
            else{
                r = i;
                curr += d;
            }
            
            if(ans < curr){
                ans = curr;
                lr[0] = l + 1, lr[1] = r + 1;
            }
        }
        if(ans < 0) return {-1};
        return lr;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        Solution ob;
        auto ans = ob.findRange(s, n);

        if (ans.size() == 1) {
            cout << ans[0] << "\n";
        } else {
            cout << ans[0] << " " << ans[1] << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends