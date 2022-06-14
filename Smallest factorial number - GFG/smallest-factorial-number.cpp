// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
    int findNum(int n){
        int low = 1, high = 5 * n;
        
        while(low < high){
            int mid = (low + high) >> 1;
            int count = 0;
            for(int i=5; i<=mid; i*=5) count += (mid/i);
            
            if(count < n) low = mid + 1;
            else high = mid;
        }
        
        return low;
    }
};

// { Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    }
return 0;
}  // } Driver Code Ends