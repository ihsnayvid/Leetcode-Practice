class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int r = mat.size(), c = mat[0].size();
        
        int low = 0, high = c-1;
        while(low < r and low >=0 and high < c and high >= 0){
            int num = mat[low][high];
            int down = (low+1 >=r ? -1 : mat[low+1][high]);
            int up = (low-1 < 0 ? -1 : mat[low-1][high]);
            int left = (high-1 < 0 ? -1 : mat[low][high-1]);
            int right = (high+1 >=c ? -1 : mat[low][high+1]);
            //cout<<num <<" | "<< up<<" "<<down<<" "<<left<<" "<<right<<endl;

            if(num > down and num > up and num > right and num > left)   
                return {low,high};

            int mxOf4 = max(up,max(down,max(left,right)));

            if(mxOf4 == up) low --;
            else if(mxOf4 == down) low ++;
            else if(mxOf4 == left) high --;
            else high ++;               

        }
        return {-1,-1};
    }
};