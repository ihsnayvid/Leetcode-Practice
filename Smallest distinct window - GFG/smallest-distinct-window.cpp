// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        set<char> s;
        for(auto c: str) s.insert(c);
        
        int i=0, j = 0, ans = INT_MAX, distinct = s.size();
        unordered_map<char,int> mp;
        while(i < str.size()){
            mp[str[i]]++;
            if(mp.size() == distinct){
                while(mp[str[j]] > 1) {
                    mp[str[j]]--;
                    j++;
                }
                
                ans = min(ans, i-j+1);
            }
            i++;
        }
        return ans;
    }
};

// { Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}  // } Driver Code Ends