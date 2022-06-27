class Solution {
public:
    int first(vector<int> a, int st, int en, int val){
        int ans = -1;
        while(st<=en){
            int mid = st + (en-st)/2;
            if(a[mid] == val){
                ans = mid;
                en = mid-1;
            }
            else if(a[mid] < val) st = mid +1;
            else en = mid - 1;
        }
        cout<<"first: "<<st<<" "<<en<<endl;
        return ans;
    }
    int last(vector<int> a, int st, int en, int val){
        int ans = -1;
        while(st<=en){
            int mid = st + (en-st)/2;
            if(a[mid] == val){
                ans = mid;
                st = mid+1;
            }
            else if(a[mid] < val) st = mid +1;
            else en = mid - 1;
        }
        cout<<"last: "<<st<<" "<<en<<endl;
        return ans;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int st = 0, en = nums.size() -1;
        int f = first(nums,st,en,target);
        int l = last(nums,st,en,target);
        return {f,l};
    }
};