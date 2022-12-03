class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for(auto i: s)
            mp[i]++;
        
        priority_queue<pair<int,char>> pq;
        for(auto i: mp)
            pq.push({i.second, i.first});
        
        string ans = "";
        while(!pq.empty()){
            auto [n,c] = pq.top();
            while(n--) ans += c;            
            pq.pop();
        }
        return ans;
    }
};