class Solution {
public:
    int a,b,c,d;
    
    bool solve(vector<int> &v, int i){
        if(v.size() == i){
            if(!a and !b and !c and !d) return true;
            else return false;
        }
        
        if(a >= v[i]){
            a -= v[i];
            if(solve(v, i+1)) return true;
            a += v[i];
        }
        if(b >= v[i]){
            b -= v[i];
            if(solve(v, i+1)) return true;
            b += v[i];
        }
        if(c >= v[i]){
            c -= v[i];
            if(solve(v, i+1)) return true;
            c += v[i];
        }
        if(d >= v[i]){
            d -= v[i];
            if(solve(v, i+1)) return true;
            d += v[i];
        }
        
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        if(matchsticks.size() < 4) return false;
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if(sum % 4 != 0) return false;
        
        a = b = c = d = sum/4;
        
        sort(matchsticks.rbegin(), matchsticks.rend());
        return solve(matchsticks, 0);
    }
};