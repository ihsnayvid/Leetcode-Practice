class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        //in, out
        vector<pair<int,int>> vp(n+1);
        for(int i=0; i<trust.size(); i++){
            vp[trust[i][0]].second++;
            vp[trust[i][1]].first++;
        }   
        for(int i=1; i<=n; i++){
            if(vp[i].first == n-1 and vp[i].second == 0)
                return i;
        }
        return -1;
    }
};