//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int longestPerfectPiece(int arr[], int n) {
        set<int> st;
        int i = 0, j = 0, ans = 0;
        
        while(j < n){
            st.insert(arr[j]);
            int mx = *(st.rbegin()), mn = *(st.begin());
            
            if(mx - mn <= 1){
                ans = max(ans, j - i + 1);
            }
            else{
                while(mx - mn > 1){
                    st.erase(arr[i]);
                    mx = *(st.rbegin()), mn = *(st.begin());
                    i++;
                }
            }
            j++;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.longestPerfectPiece(arr,N) << endl;
    }
    return 0;
}
// } Driver Code Ends