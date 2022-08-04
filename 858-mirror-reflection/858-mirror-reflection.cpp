class Solution {
public:
    int mirrorReflection(int p, int q) {
        //divide till both are even
        while(!(p&1) and !(q&1)){
            p >>= 1;
            q >>= 1;
        }
        //now both even case is impossible
        if(!(p&1)) return 2;  //p even q odd
        else if(!(q&1)) return 0;     //p odd q even
        else return 1;      //p odd q odd
    }
};