class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0, k = 0, n = nums1.size(), m = nums2.size();
        vector<int> temp;
        
        while(i<n and j<m){
            if(nums1[i] < nums2[j])
                temp.push_back(nums1[i++]);
            else
                temp.push_back(nums2[j++]);        
        }
        
        while(i<n)
                temp.push_back(nums1[i++]);
        while(j<m) 
                temp.push_back(nums2[j++]);        

        
        double median = 0, s = m+n;
        if((m+n) & 1){
            return (double)temp[s / 2];
        }
        
        else{
            double num1 = temp[s/2], num2 = temp[(s/2) - 1];
            return (num1 + num2) / 2.0;
        }
        return 0;
    }
};