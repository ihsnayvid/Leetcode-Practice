class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        if(tokens.size() == 0 or tokens[0] > power)
            return 0;
        if(tokens.size() == 1)
            return 1;
        int ans = 0;
        int res = 0;
        int j = tokens.size()-1, i = 0;
        int n = tokens.size();
        while(i<n and j>=0 and i<j){
            while(power >= tokens[i]){
                ans++;
                power -= tokens[i];
                i++;
            }
            res = max(res,ans);
            while(power<tokens[i] and ans>0){
                ans--;
                power += tokens[j];
                j--;
            }
        }
        return res;
    }
};