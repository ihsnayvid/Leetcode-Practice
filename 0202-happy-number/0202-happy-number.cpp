class Solution {
public:
    bool isHappy(int n) {
        while(n != 1){
            int x = n, sum = 0;
            while(x){
                sum += ((x%10) * (x%10));
                x /= 10;
            }
            if(sum > 1 and sum < 10 and sum != 6 and sum != 7) return false;
            n = sum;
        }
        
        return true;
    }
};