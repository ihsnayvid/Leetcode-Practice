class Solution {
public:
    int minimumLines(vector<vector<int>>& sp) {
        int n = sp.size();
        if(n == 1) return 0;
        sort(sp.begin(),sp.end());
        int count = 1;
        
        for(int i = 1; i < n-1; i++){
            long x1 = sp[i-1][0] , x2 = sp[i][0] , x3 = sp[i+1][0];
            long y1 = sp[i-1][1] , y2 = sp[i][1] , y3 = sp[i+1][1];
            
            long p1 = ((y2 - y1) * (x3 - x2));
            long p2 = ((y3 - y2) * (x2 - x1));
            if (p1 != p2)  count++;      
            
        }
        return count;
    }
};