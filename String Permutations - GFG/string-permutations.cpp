//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    void solve(int idx, string &s, vector<string> &ans){
        if(idx == s.size()){
            ans.push_back(s);
            return;
        }
        for(int i=idx; i<s.size(); i++){
            swap(s[i], s[idx]);
            solve(idx+1, s, ans);
            swap(s[i], s[idx]);
        }
    }
    vector<string> permutation(string S)
    {
        vector<string> ans;
        solve(0, S, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends