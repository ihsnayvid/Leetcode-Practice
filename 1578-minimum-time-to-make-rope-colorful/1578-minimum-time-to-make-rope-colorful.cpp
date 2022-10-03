class Solution {
public:
    int minCost(string c, vector<int>& t) {
        int sum = 0, mx = 0, ans = 0, n = c.length();
        for(int i=1; i<n; i++){
            if(c[i] == c[i-1]){
                sum = t[i-1], mx = t[i-1];
                while(c[i] == c[i-1]){
                    sum += t[i];
                    if(t[i] > mx) mx = t[i];
                    i++;
                }
                ans += (sum - mx);
            }
        }
        return ans;
    }
};