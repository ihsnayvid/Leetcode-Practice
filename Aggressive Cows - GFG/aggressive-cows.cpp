//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:

    bool check(vector<int> &arr, int n, int k, int mid){
        int cows = 1, pos = arr[0];
        for(int i=1; i<n; i++){
            if(arr[i] - pos >= mid){
                cows ++;
                if(cows == k) return true;
                pos = arr[i];
            }
        }
        return false;
    }

    int solve(int n, int k, vector<int> &arr) {
    
        sort(arr.begin(), arr.end());
        int low = 0, high = arr[n-1] - arr[0];
        int ans = INT_MAX;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(check(arr, n, k , mid)) ans = mid, low = mid + 1;
            else high = mid - 1;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends