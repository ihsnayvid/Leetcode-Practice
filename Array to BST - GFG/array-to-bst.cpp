// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    void solve(vector<int> &v, vector<int> &ans, int i, int j){
        if(i <= j){
            int mid = (i + j) >> 1;
            ans.push_back(v[mid]);
            solve(v, ans, i, mid - 1);
            solve(v, ans, mid + 1, j);
        }
    }
    vector<int> sortedArrayToBST(vector<int>& nums) {
        vector<int> ans;
        solve(nums,ans,0,nums.size() - 1);
        return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int>ans = obj.sortedArrayToBST(nums);
		for(auto i: ans)
			cout << i <<" ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends