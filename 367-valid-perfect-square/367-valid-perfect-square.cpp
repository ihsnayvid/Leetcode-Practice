class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 1) return true;
        long long low = 1, high = num/2;
        while(low <= high){
            long long mid = (low + high) >> 1;
            if(mid * mid == num) return true;
            else if (mid * mid < num) low = mid + 1;
            else high = mid - 1;
        }
        return false;
    }
};