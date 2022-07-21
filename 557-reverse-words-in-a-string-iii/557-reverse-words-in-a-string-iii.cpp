class Solution {
public:
    
    string reverseWords(string s) {
        s += ' ';
        int n = s.size(), i = 0, j = 0;
        while(i<n and j<n){
            while(s[j+1] != ' ') j++;
            
            int left = i, right = j;
            while(left < right){
                swap(s[left], s[right]);
                left++, right--;
            }
            j++;
            i = j+1;
        }
        s.erase(n-1);
        return s;
    }
};