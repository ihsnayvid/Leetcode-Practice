class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        vector<int> ans;
        if(stamp == target) return {0};
        bool check = false, found = true;
        int s = stamp.length(), t = target.length() - stamp.length() + 1, i, j;
        
        while(found){
            found = false;
            for(i=0; i<t; i++){
                check = false;
                for(j=0; j<s; j++){
                    if(target[i+j] == '$') continue;
                    else if (target[i+j] != stamp[j]) break;
                    else check = true;
                }

                if(j == s and check){
                    ans.push_back(i);
                    found = true;
                    for(int j=i; j<s+i; j++)
                        target[j] = '$';
                }
            }
        }
        
        for(i=0; i<target.size(); i++)
            if(target[i] != '$') return {};            
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};