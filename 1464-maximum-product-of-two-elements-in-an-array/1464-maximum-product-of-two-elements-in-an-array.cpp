class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto i: nums){
            pq.push(i);
            if(pq.size() > 2) 
                pq.pop();
        }
        
        int n1 = pq.top();
        pq.pop();
        int n2 = pq.top();
        return (n1-1) * (n2-1);
    }
};