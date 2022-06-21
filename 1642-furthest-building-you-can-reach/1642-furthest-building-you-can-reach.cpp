class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladder) {
        int n = heights.size(), i;        
        priority_queue<int> q;
        
        for(i=0; i<n-1; i++){
            int diff = heights[i+1] - heights[i];
            if(diff <= 0) continue;
            else{
                //use bricks or ladders
                bricks -= diff;
                q.push(diff);
                if(bricks < 0){
                    bricks += q.top();
                    q.pop();
                    ladder--;
                }
                
                if(ladder < 0) break;
            }
        }
        return i;
    }
};