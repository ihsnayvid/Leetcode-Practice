class Solution {
public:
    
    // static bool cmp(pair<int, int> &a, pair<int, int> &b){
    //     if(a.first == b.first)
    //         return a.second > b.second;
    //     return a.first > b.first;            
    // }
    
    int maxPerformance(int n, vector<int>& sp, vector<int>& ef, int k) {
        long long mod = 1e9+7;
        vector<pair<int,int>> vp;
        for(int i=0; i<n; i++)
            vp.push_back({ef[i], sp[i]});
        
        sort(vp.rbegin(), vp.rend());
        priority_queue<int, vector<int>, greater<int>> pq;
        long long ans = INT_MIN, speed = 0;
        for(int i=0; i<n; i++){
            speed += vp[i].second;
            pq.push(vp[i].second);
            if(pq.size() > k){
                speed -= pq.top();
                pq.pop();
            }
            
            ans = max(ans, speed * vp[i].first);
        }
        
        return ans % mod;
    }
};