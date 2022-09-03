class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int rs = 0, cs = 0, re = n-1, ce = n-1, x = 1;
        vector<vector<int>> m(n, vector<int>(n));
        while(rs <= re and cs <= ce){
            
            //row start
            for(int c=cs; c<=ce; c++)
                m[rs][c] = x++;
            rs++;
            
            //col end
            for(int r=rs; r<=re; r++)
                m[r][ce] = x++;
            ce--;
            
            //row end
            if(rs<=re){
                for(int c=ce; c>=cs; c--)
                    m[re][c] = x++;
            }
            re--; 
            
            //col start
            if(cs<=ce){
                for(int r=re; r>=rs; r--)
                    m[r][cs] = x++;
            }
            cs++;
        }
        
        return m;
    }
};