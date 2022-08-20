class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;
        int i = 0, n = stations.size(), dist = startFuel, ans = 0;
        while(dist < target){
            while(i < n and stations[i][0] <= dist){
                pq.push(stations[i][1]);
                i++;
            }
            if(pq.empty()) return -1;
            dist += pq.top();
            pq.pop();
            ans ++;
        }
        return ans;
    }
};