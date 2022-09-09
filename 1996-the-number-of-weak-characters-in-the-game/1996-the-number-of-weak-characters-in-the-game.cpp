class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& v) {
        sort(v.begin(), v.end());
        int n = v.size(), a = v[n-1][0], b = v[n-1][1], mx = v[n-1][1];
        int ans = 0;
        
        for(int i=n-2; i>=0; i--){
            if(v[i+1][0] > v[i][0]){                
                b = max(b, mx);
                mx = max(b, v[i][1]);                
            }
            if(v[i][0] < a and v[i][1] < b)
                ans++;
        }
        return ans;
    }
};