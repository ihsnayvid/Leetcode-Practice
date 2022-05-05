// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string stringPartition(string S, int a, int b){
        
        if(stoi(S) < 10) return "-1";
        
        string ans="";
        
        for(int i=0; i<S.size()-1; i++){
            string xx = S.substr(0,i+1);
            string yy = S.substr(i+1);
            int x = stoi(xx);
            int y = stoi(yy);
            
            if((x % a == 0) and (y % b == 0)){
                ans+= xx + " " + yy;
                return ans;
            }
        }
        return "-1";
    }
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {   
        int a,b;
        string S;
        cin >> S >> a >> b;
        Solution ob;
        cout << ob.stringPartition(S,a,b) << endl;
    }
    return 0; 
}   // } Driver Code Ends