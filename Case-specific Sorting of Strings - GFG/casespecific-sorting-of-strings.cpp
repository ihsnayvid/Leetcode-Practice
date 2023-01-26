//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        string up = "", low = "";
        for(int i=0; i<n; i++){
            if(isupper(str[i]))
                up += str[i];
            else
                low += str[i];
        }
        
        sort(up.begin(), up.end());
        sort(low.begin(), low.end());
        
        int u = 0, l = 0;
        for(int i=0; i<n; i++){
            if(isupper(str[i]))
                str[i] = up[u++];
            else
                str[i] = low[l++];
        }
        return str;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends