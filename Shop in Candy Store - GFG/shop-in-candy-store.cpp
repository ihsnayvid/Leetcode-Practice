// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int n, int k)
    {
        int a[n],d[n];
        for(int i=0;i<n;i++){
            a[i] = candies[i];
            d[i] = candies[i];
        }
        sort(a, a+n);
        sort(d,d+n,greater<int>());
        
        int i=0,j=n-1;
        int s1=0,s2=0;
        while(i<=j){
            s1+=a[i];
            s2+=d[i];
            j-=k;
            i++;
        }
        return {s1,s2};
        
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}  // } Driver Code Ends