class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        unordered_map<int,vector<int>> mp;
        vector<vector<int>> ans;
        int n = mat.size(), m = mat[0].size(), i, x, y;
        
        
        
        for(int j=0; j<m; j++){
            if(j == 0) i = n-1;
            else i = 0;
            for(; i>=0; i--){
                x = i, y = j;
                while(x < n and y < m){
                    mp[i-j].push_back(mat[x][y]);
                    x++, y++;
                }
            }
        }
        
        // for(auto &i: mp){
        //     sort(i.second.begin(), i.second.end());
        // }
        
//         for(auto i: mp){
//             for(auto v: i.second)
//                 cout<<v<<" ";
//             cout<<endl;
//         }
        
        
        // int start = n-m;
        for(int j=0; j<m; j++){
            if(j == 0) i = n-1;
            else i = 0;
            
            // cout<<i<<" "<<j<<endl;
            for(; i>=0; i--){
                vector<int> temp = mp[i-j];
                sort(temp.begin(), temp.end());
                
                // for(auto v: temp) cout<<v<<" ";
                // cout<<endl;
                // cout<<"here " <<i<<" , "<<j<<":";
                int c = 0;
                x = i, y = j;
                while(x < n and y < m){
                    // cout<<x<<" "<<y<<endl;
                    mat[x][y] = temp[c++];
                    x++, y++;
                }
                // start --;
            }
        }

        return mat;
    }
};