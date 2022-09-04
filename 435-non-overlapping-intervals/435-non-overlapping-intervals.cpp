class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){
        if(a[0] == b[0])
            return a[1] < b[1];
        return a[0] < b[0];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int count = 0;
        sort(intervals.begin(), intervals.end(), cmp);
        
        int s1 = intervals[0][0], e1 = intervals[0][1];
        for(int i=1; i<intervals.size(); i++){
            int s2 = intervals[i][0], e2 = intervals[i][1];
            if(e1 <= s2){
                s1 = s2;
                e1 = e2;
            }
            else{
                e1 = min(e1,e2);
                count++;
            }
        }
        
        return count;
    }
};