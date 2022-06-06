// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    
    public:
    long long nc2(int n){
        long long temp = n >> 1;
        return temp * (n - 1);
    }
    long long countKdivPairs(int a[], int n, int k)
    {
        unordered_map<int,int> mp;
        for(int i=0; i<n; i++)
            a[i] = a[i] % k;
        
        
        long long count = 0;
        for(int i=0; i<n; i++){
            int x = abs(k - a[i]);
            if(a[i] == 0) count += mp[0];
            else count += mp[x];
            mp[a[i]]++;
        }
        return count;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		int k;
		cin >> k;

        Solution ob;
		cout << ob. countKdivPairs(a, n , k) << "\n";



	}


	return 0;
}
  // } Driver Code Ends