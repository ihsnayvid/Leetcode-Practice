class Solution {
public:
    string pushDominoes(string d) {
        int n = d.size(), c = 1;
        char prev;
        vector<int> left(n, 0), right(n, 0);
        for(int i=0; i<n; i++){
            if(d[i] != '.') {
                c = 1;
                prev = d[i];
            }
            if(prev == 'R' and d[i] == '.') right[i] = c++;
        }
        c = 1;
        prev = '.';
        for(int i=n-1; i>=0; i--){
            if(d[i] != '.') {
                c = 1;
                prev = d[i];
            }
            if(prev == 'L' and d[i] == '.') left[i] = c++;
        }
        
        string ans = "";
        
        for(int i=0; i<n; i++){
            if(!left[i] and !right[i]) ans += d[i];
            else if(!left[i]) ans += 'R';
            else if(!right[i]) ans += 'L';
            else if(left[i] == right[i]) ans += '.';
            else if(left[i] < right[i]) ans += 'L';
            else ans += 'R';
        }
        return ans;
    }
};