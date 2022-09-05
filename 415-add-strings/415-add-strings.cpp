class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans = "";
        int carry = 0;
        int a = num1.length() - 1, b = num2.length() - 1;
        while(a >= 0 or b >= 0 or carry == 1){
            carry += (a >= 0) ? num1[a] - '0' : 0;
            carry += (b >= 0) ? num2[b] - '0' : 0;
            
            ans = (char) (carry % 10  + '0') + ans;
            carry /= 10;
            a--, b--;
        }
        return ans;
    }
};