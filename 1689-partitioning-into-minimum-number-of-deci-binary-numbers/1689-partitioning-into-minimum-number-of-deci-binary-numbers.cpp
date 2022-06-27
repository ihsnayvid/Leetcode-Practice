class Solution {
public:
    int minPartitions(string n) {
        int mx = 0;
        for(auto i: n) if(i-'0' > mx) mx = i-'0';
        return mx;
    }
};