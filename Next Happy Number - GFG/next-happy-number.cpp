//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    bool isHappy(int n) {
        while(n != 1){
            int x = n, sum = 0;
            while(x){
                sum += ((x%10) * (x%10));
                x /= 10;
            }
            if(sum > 1 and sum < 10 and sum != 6 and sum != 7) return false;
            n = sum;
        }
        return true;
    }
    int nextHappy(int n){
        for(int i=n+1; i<1e9; i++){
            if(isHappy(i)) return i;
        }
        return n;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.nextHappy(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends