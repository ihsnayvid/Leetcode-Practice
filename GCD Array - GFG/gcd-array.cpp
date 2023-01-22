//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    int solve(int n, int k, vector<int> &arr) {
        vector<int> prefix;
        vector<int> factors;
        int sum = 0;
        for(auto i: arr){
            sum += i;
            prefix.push_back(sum);
        }
        
        for(int i=1; i<=sqrt(sum); i++){
            if(sum % i == 0){
                factors.push_back(i);
                if(i != sum/i) factors.push_back(sum / i);
            }
        }
        
        int ans = 0;
        for(auto f: factors){
            int count = 0;
            for(auto i: prefix){
                if(i % f == 0) count++;
            }
            
            if(count >= k){
                ans = max(ans, f);
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        
        vector<int> arr(N);
        Array::input(arr,N);
        
        Solution obj;
        int res = obj.solve(N, K, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends