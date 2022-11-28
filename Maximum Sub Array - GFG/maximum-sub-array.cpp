//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	vector<int> findSubarray(int a[], int n) {
	    vector<int> ans;
	    int curr = 0, mx = INT_MIN, i = 0, j = 0, st = 0, en = 0;
	    while(j < n){
	        if(a[j] >= 0){
	            curr += a[j];
	            j ++;
	        }
	        else{
	           if(curr > mx){
                    mx = curr;
                    st = i;
                    en = j;
	           }
	           curr = 0;
	           j++;
	           i = j;
	        }
	    }
	    
	    if(curr > mx){
	        st = i;
	        en = j;
	    }
	    
	    for(int i=st; i<en; i++)
	        ans.push_back(a[i]);
	    
	    if(ans.empty()) ans.push_back(-1);
	    return ans;
	}
};

//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findSubarray(a, n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends