class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        long n = arr.size(), ans = 0, mod = 1e9+7;
        vector<int> left(n, -1), right(n, n);
        stack<int> st;
        
        for(int i=0; i<n; i++){
            while(!st.empty() and arr[st.top()] > arr[i])
                st.pop();
            if(!st.empty()) left[i] = i - st.top();
            else left[i] = i+1;
            st.push(i);
        }
        
        while(!st.empty()) st.pop();
        
        for(int i = n-1; i>=0; i--){
            while(!st.empty() and arr[st.top()] >= arr[i])
                st.pop();
            if(!st.empty()) right[i] = st.top() - i;
            else right[i] = n - i;
            st.push(i);
        }
        
        for(int i=0; i<n; i++){
            ans = (ans % mod) + ((((left[i] * right[i]) % mod) * arr[i]) % mod);
        }
        return ans;
    }
};