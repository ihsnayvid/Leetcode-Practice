class Solution {
public:
    int calculate(string s) {
        stack <int> st, op;
        long num = 0, ans = 0, sign = 1;
        for (char c : s) { 
            if (isdigit(c))
                num = num * 10 + c - '0';
            else{
                ans += sign * num;
                num = 0;
                if (c == '+') sign = 1;
                else if (c == '-') sign = -1;
                else if (c == '(') {
                    st.push(ans);
                    op.push(sign);
                    ans = 0;
                    sign = 1;
                }
                else if (c == ')' and op.size()) {
                    ans = op.top() * ans + st.top();
                    op.pop(); st.pop();
                }
            }
        }
        ans += sign * num;
        return ans;
    }
};