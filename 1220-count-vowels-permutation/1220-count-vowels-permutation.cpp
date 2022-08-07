static vector<vector<int>> rel = {{1,2,4},{0,2},{1,3},{2},{2,3}};  
class Solution {
public:
    int countVowelPermutation(int n) 
    {
        int MOD = 1e9+7;
        vector<long long> vowels(5,1), vowelsCopy;      
        long long ans = 0;
        while(--n){
            vowelsCopy = vowels;
            for(int i=0; i<5; i++){
                vowels[i] = 0;
                for(int &r: rel[i])
                    vowels[i] += vowelsCopy[r], vowels[i] %= MOD;  
            }
        }
        for(long long &i: vowels)
            ans += i, ans %= MOD;
        return ans;
    }
};