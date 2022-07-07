// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int primeFactors(int n){
	    //if(n == 1) return 0;
	    int c = 0;
	    int y = n;
	    for(int i=2; i<= y/2; i++){
	        while(n%i == 0){
	            c++;
	            n /= i;
	        }
	    }
	    return c;
	}
	bool isPrime(int n){
	    for(int i=2; i<=sqrt(n); i++){
	        if(n%i == 0) return false;
	    }
	    return true;
	}
    bool brainGame(vector<int>nums) {
        int ans = 0;
     
        for(auto i:nums){
            if(!isPrime(i)){
                ans = ans ^ (primeFactors(i) - 1);
                //cout<<primeFactors(i)-1<<endl;
            }
        }  
        
        return ans != 0;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution ob;
		bool ans = ob.brainGame(nums);
		if(ans)
			cout << "A\n";
		else cout << "B\n";
	}  
	return 0;
}  // } Driver Code Ends