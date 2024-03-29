class Solution {
public:
    int solve(vector<string> & arr, string str, int idx){
        unordered_set<char>s (str.begin(), str.end());
        if (s.size() != ((int)str.length())) 
            return 0;
        
        int ans = str.length();
        for (int i = idx; i<arr.size(); i++)
            ans = max(ans, solve(arr, str + arr[i], i + 1));

        return ans;
    }
    int maxLength(vector<string>& arr) {
        return solve(arr, "", 0);
    }
};