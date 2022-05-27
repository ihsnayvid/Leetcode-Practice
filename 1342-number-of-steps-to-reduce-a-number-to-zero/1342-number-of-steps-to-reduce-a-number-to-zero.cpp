class Solution {
public:
    int numberOfSteps(int num) {
        if(num == 0) return 0;
        int steps = 0;
        while(num){
            if(num & 1) num --;
            else num >>= 1;
            steps ++;
        }
        return steps;
    }
};