// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countSetBits(int n){
        int count = 0;
        while(n){
            n &= (n-1);
            count++;
        }
        return count; 
    }
    int minVal(int a, int b) {
        int bitsA = countSetBits(a), bitsB = countSetBits(b);
        if(bitsA == bitsB) return a;
        
        int diff = abs(bitsA - bitsB), x = 1, ta = a;
        while(diff > 0){
            int i = (bitsA > bitsB) ? x : 0;
            if((x & ta) == i){
                ta ^= x;
                diff--;
            }
            x <<= 1;
        }
        
        return ta;
    }
};

// { Driver Code Starts.

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
}  // } Driver Code Ends