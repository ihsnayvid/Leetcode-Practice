//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minVal(int num1, int num2) {
        int set1 = __builtin_popcount(num1);
        int set2 = __builtin_popcount(num2);
        
        if(set1 == set2) return num1;
        vector<long> a(32);
        int k = 31;
        int n = num1;
        while(n){
            a[k--] = (n&1);
            n >>= 1;
        }
        // for(auto i: a) cout<<i<<" ";
        // cout<<endl;
        int diff = abs(set1-set2);
        if(set1 > set2){
            for(int i=a.size()-1; i>=0; i--){
                if(diff == 0) break;
                if(a[i] == 1) a[i] = 0, diff --;
            }
        }
        else{
            for(int i=a.size()-1; i>=0; i--){
                if(diff == 0) break;
                if(a[i] == 0){
                    a[i] = 1; 
                    diff --;
                }
            }
        }
        
        int ans = 0;
        for(auto i: a){
            // cout<<i<<" ";
            ans <<= 1;
            ans |= i;
        }
        return ans;

    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends