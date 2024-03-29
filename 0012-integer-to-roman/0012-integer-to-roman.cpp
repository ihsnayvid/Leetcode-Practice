class Solution {
public:
    string intToRoman(int num) {
        vector<string> o = {"" , "I" , "II" , "III" , "IV" , "V" , "VI" , "VII" , "VIII" , "IX"};
        vector<string> t = {"" , "X" , "XX" , "XXX" , "XL" , "L" , "LX" , "LXX" , "LXXX" , "XC"};
        vector<string> h = {"" , "C" , "CC" , "CCC" , "CD" , "D" , "DC" , "DCC" , "DCCC" , "CM"};
        vector<string> th ={"" , "M" , "MM" , "MMM"};
        
        return th[num / 1000] + h[(num % 1000) / 100] + t[(num % 100) / 10] + o[num % 10];
    }
};