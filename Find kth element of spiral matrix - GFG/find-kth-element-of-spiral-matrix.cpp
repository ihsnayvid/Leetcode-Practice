//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    /*You are required to complete this method*/
  
    int findK(int a[MAX][MAX],int n,int m,int k)
    {
 		int rs = 0, cs = 0, re = n-1, ce = m-1, count = 0;
 		while(rs <= re and cs <= ce){
 		    for(int col = cs; col <= ce; col++) {
 		        count++;
 		        if(count == k) return a[rs][col];
 		    }
 		    rs++;
 		    
 		    for(int row = rs; row <= re; row++) {
 		        count++;
 		        if(count == k) return a[row][ce];
 		        
 		    }
 		    ce--;
 		    
 		    if(rs <= re){
                for(int col = ce; col >= cs; col --) {
                    count++;
 		            if(count == k) return a[re][col];
                    
                }
                re--;
                
            }

            if(cs <= ce){                
                for(int row = re; row >= rs; row--) {
                    count++;
 		            if(count == k) return a[row][cs];
                    
                }
                cs++;            
            }
 		}
 		return -1;
    }
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends