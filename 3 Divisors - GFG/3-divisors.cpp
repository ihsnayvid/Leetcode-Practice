//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution
{
public:
   int m = 1000001;
    void sieve(vector<long long int>& isPrime,vector<long long int>& primes){    
        //memset(isPrime,true,sizeof(isPrime));
        isPrime[0]=false;
        isPrime[1]=false;
        for(long long int i=2;i<=sqrt(m);i++){
            if(isPrime[i]){
                for(long long int j=i*i;j<=m;j+=i)
                    isPrime[j]=false;
            }
        }
        int count = 0;
        for(int i = 2; i <= m; i++){
            if(isPrime[i]) count++;
            primes[i] = count;
        }
    }
    vector<int> threeDivisors(vector<long long> query, int q)
    {
        vector<long long int>isPrime(1000001,1);
        vector<long long int>primes(1000001,0);
        sieve(isPrime,primes);
        vector<int> ans;
        for(auto i=0;i<q;i++) 
            ans.push_back(primes[int(sqrt(query[i]))]);
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while(t--){
        int q;cin>>q;
        vector<long long> query(q);
        for(int i=0;i<q;i++){
            cin>>query[i];
        }
        Solution ob;
            
        vector<int> ans = ob.threeDivisors(query,q);
        for(auto cnt : ans) {
            cout<< cnt << endl;
        }
    }
    return 0;
}
// } Driver Code Ends