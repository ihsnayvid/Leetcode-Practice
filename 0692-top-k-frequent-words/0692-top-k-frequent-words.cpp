class Solution {
public:
    struct cmp{
        bool operator() (const pair<int, string> &a, const pair<int, string> &b){
            if(a.first == b.first) return a.second < b.second;
            else return a.first > b.first;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for(auto w: words)
            mp[w]++;
        
        priority_queue<pair<int,string>, vector<pair<int,string>>, cmp> pq;
        for(auto i: mp){
            pq.push({i.second, i.first});
            if(pq.size() > k)
                pq.pop();
        }
        
        vector<string> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};