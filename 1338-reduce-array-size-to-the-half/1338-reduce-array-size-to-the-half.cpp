class Solution {
public:
    int minSetSize(vector<int>& arr) {
        priority_queue<int> pq;
        unordered_map<int,int> mp;
        for(auto i: arr)
            mp[i]++;
        for(auto i: mp)
            pq.push(i.second);
        
        int size = arr.size(), ans = 0;
        while(size > arr.size() / 2){
            ans ++;
            size -= pq.top();
            pq.pop();
        }
        return ans;
    }
};