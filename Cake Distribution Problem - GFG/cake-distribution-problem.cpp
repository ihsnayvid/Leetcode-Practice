//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    
    bool check(vector<int> &v, int mid, int k){
        int sweet = 0, c = 0;
        for(int &i: v){
            sweet += i;
            if(sweet >= mid){
                sweet = 0;
                c++;
            }
        }
        return c > k;
    }
    int maxSweetness(vector<int>& sw, int n, int k) {
        int high = accumulate(sw.begin(), sw.end(), 0LL);
        int low = 1, ans = 1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(check(sw, mid, k)){
                ans = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> sweetness(n);
        for (int i = 0; i < n; i++) {
            cin >> sweetness[i];
        }
          Solution ob;
          int res=ob.maxSweetness(sweetness, n, k);
        cout << res << endl;
    }
}
// } Driver Code Ends