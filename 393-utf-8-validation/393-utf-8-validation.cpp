class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int c = 0;
        for(auto i: data){
            if(!c){ //first byte/ int
                if((i >> 5) == 0b110) c = 1; //2 bit->check next 1 bit
                else if((i >> 4) == 0b1110) c = 2; //3 bit->check next 2 bit
                else if((i >> 3) == 0b11110) c = 3; //4 bit->check next 3 bit
                else if((i >> 7)) return false; // 1 bit but first digit not zero
            }
            else{
                if((i >> 6) != 0b10) return false;
                c--;
            }            
        }
        
        return c == 0;
    }
};