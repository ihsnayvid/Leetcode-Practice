//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int solve(int a, int b, int c) {
        int aa = 0, bb = 0, cc = 0, ans = 0, n = a + b + c;
        int total = n;
        // bool flaga = false, flagb = false, flagc = false;
        while(n--){
            if((a >= b and a >= c and aa < 2) or (a > 0 and (bb == 2 or cc == 2))){
                // flaga = 1;
                ans++;
                a--;
                aa++;
                bb = 0, cc = 0;
            }
            else if((b >= a and b >= c and bb < 2) or (b > 0 and (aa == 2 or cc == 2))){
                // flagb = 1;
                ans++;
                b--;
                bb++;
                aa = 0, cc = 0;
            }
            else if((c >= b and c >= a and cc < 2) or (c > 0 and (bb == 2 or aa == 2))){
                // flagc = 1;
                ans++;
                c--;
                cc++;
                bb = 0, aa = 0;
            }
        }
        // return flaga and flagb and flagc ? ans : -1;
        // cout<<ans<<" "<<n<<" ";
        return ans ==  total? ans : -1;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int a, b, c;
        cin >> a >> b >> c;

        Solution ob;
        int ans = ob.solve(a, b, c);
     

        cout <<  ans << "\n";
    }
    return 0;
}
// } Driver Code Ends