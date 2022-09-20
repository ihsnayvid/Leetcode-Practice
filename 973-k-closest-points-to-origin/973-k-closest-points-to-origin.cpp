class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<long,int>> pq;
        
        for(int i=0; i<points.size(); i++){
            int x = points[i][0], y = points[i][1];
            long distance = ((x*x) + (y*y));
            pq.push({distance, i});
            if(pq.size() > k) pq.pop();
        }
        
        vector<vector<int>> ans;
        while(!pq.empty()){
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }
        return ans;
    }
};