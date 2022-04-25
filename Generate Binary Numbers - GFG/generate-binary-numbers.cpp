// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

//Function to generate binary numbers from 1 to N using a queue.
vector<string> generate(int n)
{
    if(n == 1) return {"1"};
	queue<string> q;
	q.push("1");
	vector<string> v(n);
	v[0] = "1";
	for(int i=1;i<n;i+=2){
	    v[i] = q.front() + "0";
	    q.push(v[i]);
	    if(i+1 < n){
	        v[i+1] = q.front() + "1";
	        q.push(v[i+1]);
	    }
	    q.pop();
	}
	return v;
}


// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<string> ans = generate(n);
		for(auto it:ans) cout<<it<<" ";
		cout<<endl;
	}
	return 0;
}  // } Driver Code Ends