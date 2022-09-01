class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){
        if(a[0] == b[0])
            return a[1] < b[1];
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end(), cmp);
        
        int s1 = intervals[0][0], e1 = intervals[0][1];
        for(int i=1; i<intervals.size(); i++){
            int s2 = intervals[i][0], e2 = intervals[i][1];
            if(e1 < s2){
                ans.push_back({s1, e1});
                s1 = s2;
                e1 = e2;
            }
            else
                if(e1 < e2)
                    e1 = e2;
        }
        ans.push_back({s1,e1});
        return ans;
    }
};