// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int a[], int n, int k)
    {
        sort(a, a+n);
        int i=0,j=n-1,x=n-1,y=0;
        int s1=0,s2=0;
        while(i<=j){
            s1+=a[i];
            s2+=a[x];
            j-=k;
            i++;
            y+=k;
            x--;
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