class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b){
        return a[1] > b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(),cmp);
        
        int ans = 0;
        for(auto v: boxTypes){ 
            if(truckSize == 0) break;
            if(truckSize - v[0] >= 0){
                ans += v[0] * v[1];
                truckSize -= v[0];
            }
            else{
                ans += truckSize * v[1];
                truckSize = 0;
            }
        }
        return ans;
    }
};