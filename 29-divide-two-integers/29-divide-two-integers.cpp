class Solution {
public:
    
    int divide(int dividend, int divisor) {
        
        if(dividend==INT_MIN && divisor==-1) return INT_MAX;

        int sign;
        if((dividend < 0 and divisor > 0 ) or dividend > 0 and divisor < 0) sign = -1;
        else sign = 1;
        
        long dd = abs(dividend);
        long dv = abs(divisor);
        
        long ans = 0;
        while (dd >= dv) {
            long temp = dv, m = 1;
            while (temp << 1 <= dd) {
                temp <<= 1;
                m <<= 1;
            }
            dd -= temp;
            ans += m;
        }
        return (ans * sign);
    }
};