//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	vector<vector<int>> ans;
	
	void solve(int n, vector<int> &ds){
	   if(n == 0){
	       ans.push_back(ds);
	       return;
	   }
	   
	   for(int i=0; i<n; i++){
	       if(ds.empty() or n-i <= ds.back()){
	           ds.push_back(n-i);
	           solve(i, ds);
	           ds.pop_back();
	       }
	   }
	}
	
    vector<vector<int>> UniquePartitions(int n) {
        vector<int> ds;
        solve(n, ds);
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		vector<vector<int>> ans = ob.UniquePartitions(n);
    	for(auto i : ans)
    		for(auto j: i)
    			cout << j <<" ";
    	cout << "\n";
	}  
	return 0;
}
// } Driver Code Ends