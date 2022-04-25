class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> arr=nums;
        for(int i=0;i<nums.size();i++) {
            arr.push_back(nums[i]);
            
        }
        
        stack<int> s;
        vector<int> v(nums.size(),-1);
        
        
        for (int i=2* nums.size()-1;i>=0;i--){            
            if(s.size() > 0 && s.top() > arr[i] && i<nums.size()) v[i]=s.top();
            else if(s.size() > 0 && s.top() <= arr[i]){
                while(s.size() > 0 && s.top() <= arr[i]) s.pop();
                if(s.size() > 0 and i< nums.size())
                    v[i] = s.top();
            }
            s.push(arr[i]);
        }
        return v;
    }
};