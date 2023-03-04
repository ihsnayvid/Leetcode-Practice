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
    long long bestNode(int n, vector<int> &a, vector<int> &p) {
        unordered_set<int> st(p.begin(), p.end());
        vector<int> leaf;
        
        for(int i=1; i<=n; i++){
            if(!st.count(i)) leaf.push_back(i);
        }
        
        long long sum = 0, ans = INT_MIN;
        for(auto i: leaf){
            sum = 0;
            while(i != -1){
                sum *= -1;
                sum += a[i-1];
                i = p[i-1];
                ans = max(ans, sum);
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
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        
        vector<int> P(N);
        Array::input(P,N);
        
        Solution obj;
        long long res = obj.bestNode(N, A, P);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends