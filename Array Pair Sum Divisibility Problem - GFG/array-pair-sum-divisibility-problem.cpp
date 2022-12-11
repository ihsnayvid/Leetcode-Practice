//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        if(nums.size() % 2 != 0) return false;
        
        unordered_map<int, int> mp;
        for(auto i: nums)
            mp[i % k]++;
            
        // for(auto i: mp) cout<<i.first <<" - "<<i.second<<endl;
        for(auto i: mp){
            if(i.second > 0){
                if(i.first > 0 and i.first != k - i.first and mp[k - i.first] > 0){
                    int count = min(mp[i.first], mp[k - i.first]);
                    mp[i.first] -= count;
                    mp[k - i.first] -= count;
                }
            }
        }
        
        // for(auto i: mp) cout<<i.first <<" - "<<i.second<<endl;
        
        if(mp[0] > 0){
            if(mp[0] % 2 != 0) return false;
            else mp[0] = 0;
        }
        if(k %2 == 0 and mp[k/2] > 0){
            if(mp[k/2] % 2 != 0) return false;
            else mp[k/2] = 0;
        }
        
        for(auto i: mp){
            // cout<<i.first <<" - "<<i.second<<endl;
            if(i.second != 0) return false;
        }
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends