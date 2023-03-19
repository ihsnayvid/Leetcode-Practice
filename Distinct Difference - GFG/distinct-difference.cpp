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
    vector<int> getDistinctDifference(int n, vector<int> &a) {
        unordered_map<int, int> mpl, mpr;
        unordered_set<int> stl, str;
        for(int i=0; i<n; i++){
            mpl[i] = stl.size();
            stl.insert(a[i]);
        }
        
        for(int i=n-1; i>=0; i--){
            mpr[i] = str.size();
            str.insert(a[i]);
        }
       
        vector<int> ans(n);
        for(int i=0; i<n; i++)
            ans[i] = mpl[i] - mpr[i];
        
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
        
        Solution obj;
        vector<int> res = obj.getDistinctDifference(N, A);
        
        Array::print(res);
        
    }
}

// } Driver Code Ends