//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int missingNumber(int a[], int n);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int i=0, n;
		cin>>n;
		int a[n+5];
		for(i=0;i<n-1;i++)
			cin>>a[i];
			
		cout<<missingNumber(a, n)<<endl;
	}
}
// } Driver Code Ends


int missingNumber(int a[], int n)
{
    unordered_set<int> st;
    for(int i=0; i<n; i++)
        st.insert(a[i]);
    
    for(int i=1; i<=n; i++){
        if(st.count(i) == 0) return i;
    }
    return -1;
}