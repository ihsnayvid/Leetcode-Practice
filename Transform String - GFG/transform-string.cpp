// { Driver Code Starts
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    int transform (string a, string b)
    {
        //ensuring same length
        int na = a.length();
        int nb = b.length();
        if(na != nb) return -1;
        
        //ensuring same characters
        int i = 0, j = 0, sum = 0;
        while(i<na){
            sum += a[i];
            sum -= b[j];
            i++;
            j++;
        }
        if(sum) return -1;
        
        
        i = na-1, j = nb - 1;
        int ans = 0;
        
        while(i >= 0 and j >= 0){
            if(a[i] == b[j]){
                i-- , j-- ;
            }
            else{
                i-- , ans++;
            }
        }
        return ans;
    }
};


// { Driver Code Starts.

int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution ob;
        cout <<ob.transform (A, B) << endl;
    }
}  // } Driver Code Ends