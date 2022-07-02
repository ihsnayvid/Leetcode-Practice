class Solution {
public:
    string removeDigit(string number, char digit) {
        string ans = "";
        long long mx = INT_MIN;
        for(int i=0; i<number.size(); i++){
            string str ="";
            if(number[i] == digit){
                str += number.substr(0,i) + number.substr(i+1);
                if(str > ans) ans = str;
            }
        }
        if(ans != "") return ans;
        return number;
    }
};