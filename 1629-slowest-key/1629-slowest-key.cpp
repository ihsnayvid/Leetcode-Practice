class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int mx = releaseTimes[0], idx = 0;
        
        for(int i=1; i<releaseTimes.size(); i++){
            int diff = releaseTimes[i] - releaseTimes[i-1];
            if(diff > mx){
                mx = diff;
                idx = i;
            }
            else if(diff == mx and keysPressed[i] > keysPressed[idx])
                idx = i;
        }
        
        return keysPressed[idx];
    }
};