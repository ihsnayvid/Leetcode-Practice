// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
public:
    int countDistinctSubarray(int arr[], int n)
    {
        unordered_map<int,int> mp;
        for(int i=0; i<n; i++) mp[arr[i]]++;
        
        int k = mp.size();
        if(k == n) return 1;
        
        mp.clear();
        int count = 0, i = 0, j = 0;
        //unordered_map<int,int> mpp;
        while(i<n and j<n){
            mp[arr[i]]++;
            if(mp.size() < k) i++;
            else{
                 count += n-i;
                 mp[arr[j]]--;
                 mp[arr[i]]--;
                 if(mp[arr[j]] == 0) mp.erase(arr[j]);
                 j++;
                 if(i<j) i = j;
            }
        }
        
        return count;
    }
};


// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;	
		cout<<ob.countDistinctSubarray(a,n)<<endl;
	}
	return 0;
}  // } Driver Code Ends