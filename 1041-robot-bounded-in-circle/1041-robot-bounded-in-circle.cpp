class Solution {
public:
    
    bool isRobotBounded(string instructions) {
        // char dir[] = {'n', 'e', 's', 'w'};
        int x = 0, y = 0, dir = 0;
        int n = 4;
        while(n--){
            for(auto i: instructions){
                if(i == 'L'){
                    dir--;
                    if(dir == -1) dir = 3;
                }
                else if(i == 'R'){
                    dir++;
                    if(dir == 4) dir = 0;
                }
                else{
                    if(dir == 0) y++;
                    else if(dir == 1) x++;
                    else if(dir == 2) y--;
                    else x--;
                }
            }
        }
        if(x == 0 and y == 0) return true;
        return false;
    }
};