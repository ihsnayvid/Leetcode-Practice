// { Driver Code Starts
#include <iostream>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    long gcd(long a, long b){
        if(a == 0) return b;
        return gcd(b%a, a);
    }
    long ncr(int n, int r){
        if(n<r) return 0;
        if(n-r < r) r = n-r;
        if(r == 0) return 1; 
        long p = 1, q = 1;
        while(r){
            p *= n;
            q *= r;
            long g = gcd(p,q);
            
            p /= g;
            q /= g;
            
            n--;
            r--;
            //cout<<p<<","<<q<<endl;
        }
    
        return p/q;
    }
    
    long posIntSol(string s)
    {
        long n=0, r=0;
        string sum="";
        for(int i=0; i<s.size(); i++){
            if(s[i]>='a' and s[i]<='z') r++;
            else if(s[i] == '='){
                i++;
                while(i<s.size())
                    sum += s[i++];
            }
        }
        n = stoi(sum);
        //cout<<n<<" "<<r<<endl;
        return ncr(n-1,r-1);
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.posIntSol(s)<<endl;
    }
    return 0;
}
  // } Driver Code Ends