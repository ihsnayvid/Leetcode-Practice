class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> mp;    //map to store last index of each character
        int last = -1, mx = INT_MIN;
        vector<int> ans;
        
        for(int i=0; i<s.size(); i++)
            mp[s[i]] = i;
            
        for(int i=0; i<s.size(); i++){
            mx = max(mx, mp[s[i]]); //stores the farthest index of current partition characters
            if(mx == i){            //current idx is the max till now
                ans.push_back(i-last);
                last = i;
            }
        }
        return ans;
    }
};