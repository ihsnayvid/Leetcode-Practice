// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> numAndDen(int n, int d) {
        int num = -1, den = 1;
        for (int i = d + 1; i <= 10000; i++){
            int j = (i * n) / d;
            if(__gcd(j,i) == 1){
                if((1.0 * j/i) > (1.0 * num/den))
                    num = j, den = i;
            }
        }
        return {num,den};
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,d;
        cin >> n >> d;
        Solution ob;
        vector<int>ans=ob.numAndDen(n,d);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
  // } Driver Code Ends