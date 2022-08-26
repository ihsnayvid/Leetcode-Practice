class Solution {
public:
    /* 1 2 4 8 16 32 64 128 258 512 1024
    16->10000
    61->111101
    
    32 -> 100000
    23 -> 101111

    */
    bool reorderedPowerOf2(int n) {
        string s = to_string(n);
        sort(s.begin(), s.end());
        
        for(int i=0; i<=30; i++){
            int x = pow(2,i);
            string curr = to_string(x);
            sort(curr.begin(), curr.end());
            if(curr == s)
                return true;
        }
        return false;
    }
};