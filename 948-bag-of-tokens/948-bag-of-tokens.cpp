class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        int ans = 0, i = 0, j = n-1, score = 0;
        sort(tokens.begin(), tokens.end());
        while(i <= j){
            if(power >= tokens[i]){
                power -= tokens[i];
                score ++;
                ans = max(ans, score);
                i++;
            }
            else if(score > 0){
                power += tokens[j];
                score --;
                j--;
            }
            else break;
        }
        return ans;        
    }
};