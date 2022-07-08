class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        vector<int> left(n), right(n);
        for(int i=0; i<n; i++){
            while(!st.empty() and heights[st.top()] >= heights[i])
                st.pop();
            if(!st.empty()) left[i] = st.top() + 1;
            else left[i] = 0;
            st.push(i);
        }
        
        while(!st.empty()) st.pop();        
        
        for(int i=n-1; i>=0; i--){
            while(!st.empty() and heights[st.top()] >= heights[i])
                st.pop();
            if(!st.empty()) right[i] = st.top() - 1;
            else right[i] = n-1;
            st.push(i);
            
        }
        
        int ans = INT_MIN;
        for(int i=0; i<n; i++)
            ans = max(ans, (right[i] - left[i] + 1 ) * heights[i]);
        
        return ans;
    }
};