//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    string longestString(vector<string> &words)
    {
        unordered_map<string, int> mp;
        for(auto i: words) mp[i] ++;
        
        string ans = "";
        int len = 0;
        for(auto w: words){
            if(w.length() > len or (w.length() == len and w < ans)){
                bool check = true;
                string pre = "";
                for(auto i: w){
                    pre += i;
                    if(mp.find(pre) == mp.end()){
                        check = false;
                        break;
                    }
                }
                if(check){
                    len = w.length();
                    ans = w;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution obj;
        string w = obj.longestString(v);
        cout << w << "\n";
    }
    return 0;
}

// } Driver Code Ends