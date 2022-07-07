class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> num;
        int fact = 1;
        for(int i=1; i<n; i++){
            fact *= i;
            num.push_back(i);
        }
        num.push_back(n);
        k--;
        //cout<<fact;
        string ans = "";
        while(true){
            ans += to_string(num[k / fact]);
            num.erase(num.begin() + (k / fact));
            if(!num.size()) break;
            k %= fact;
            fact /= num.size();
        }
        
        return ans;
    }
};