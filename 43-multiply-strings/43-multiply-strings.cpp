class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans = "";
        int carry = 0;
        int a = num1.length() - 1, b = num2.length() - 1;
        while(a >= 0 or b >= 0 or carry == 1){
            carry += (a >= 0) ? num1[a] - '0' : 0;
            carry += (b >= 0) ? num2[b] - '0' : 0;
            
            ans = (char) (carry % 10  + '0') + ans;
            carry /= 10;
            a--, b--;
        }
        return ans;
    }
    string multiply(string num1, string num2) {
        int a = num1.length()-1, b = num2.length()-1, k = 0;
        string ans = "";
        
        if(num1 == "0" or num2 == "0") return "0";
        if(num1 == "1") return num2;
        else if(num2 == "1") return num1;
    
        for(int i=a; i>=0; i--){
            string str = "";
            long long num = 0, carry = 0;
            for(int j=b; j>=0; j--){
                // cout<<(num1[i] - '0') << " * "<<(num2[j] - '0')<<" = ";
                long long x = (num1[i] - '0') * (num2[j] - '0');
                // cout<<x<<"\n";
                carry += x;
                str = to_string(carry%10) + str;
                // cout<<str<<"\n";
                carry /= 10;
            }  
            if(carry) str = to_string(carry) + str;
            // cout<<str<<"\n";
            for(int zero = 0; zero<k; zero++)
                str += '0';
            ans = addStrings(ans, str);
            k++;
        }
        return ans;
    }
};