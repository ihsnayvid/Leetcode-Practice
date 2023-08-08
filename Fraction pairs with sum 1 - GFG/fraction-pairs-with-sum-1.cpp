//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    // static bool cmp(pair<int, int> &a, pair<int, int> &b){
    //     if(a.second == b.second) return a.first < b.first;
    //     return a.second < b.second;
    // }
    int countFractions(int n, int numerator[], int denominator[])
    {
    //     vector<pair<int, int>> vp;
    //     for(int i=0; i<n; i++){
    //         int g = __gcd(numerator[i], denominator[i]);
    //         vp.push_back({numerator[i]/g, denominator[i]/g});
    //     }
        
    //     sort(vp.begin(), vp.end(), cmp);
        
        map<pair<int, int>, int> mp;
        int count = 0;
        for(int i=0; i<n; i++){
            int g = __gcd(numerator[i], denominator[i]);
            int num = numerator[i]/g;
            int den = denominator[i]/g;
            
            int comp = den - num;
            count += mp[{comp, den}];
            mp[{num, den}]++;
        }
        return count;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int numerator[n],denominator[n];
        for(int i=0;i<n;i++)
            cin>>numerator[i];
        for(int i=0;i<n;i++)
            cin>>denominator[i];
        Solution ob;
        int ans=ob.countFractions(n,numerator,denominator);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends