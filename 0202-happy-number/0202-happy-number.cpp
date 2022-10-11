class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> st;
        while(n){
            int x = n, sum = 0;
            while(x){
                sum += ((x%10) * (x%10));
                x /= 10;
            }
            // cout<<sum<<"\n";
            if(st.count(sum)) return false;
            if(sum == 1) return true;
            st.insert(sum);
            n = sum;
        }
        
        return true;
    }
};