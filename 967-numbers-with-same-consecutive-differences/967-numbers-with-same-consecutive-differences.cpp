class Solution {
public:
    
    void solve(int n, int d, int k, vector<int> &ans){
        if(n == 0){
            ans.push_back(d);
            return;
        }
        
        int val = d % 10;
        if(val + k >= 0 and val + k < 10){
            int temp = d * 10 + (val + k);
            solve(n-1, temp, k, ans);
        }
        
        if(k != 0 and val - k >= 0 and val - k < 10){
            int temp = d * 10 + (val - k);
            solve(n-1, temp, k, ans);
        }
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        for(int i=0; i<9; i++)
            solve(n-1, i+1, k, ans);
        return ans;
    }
};