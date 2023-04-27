//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<char> easyTask(int n,string s,int q,vector<vector<string>> &queries){
        vector<char> ans;
        for(auto &i: queries){
            if(i[0] == "1")
                s[stoi(i[1])] = i[2][0];
            else{
                int l = stoi(i[1]), r = stoi(i[2]), k = stoi(i[3]);
                vector<int> freq(26, 0);
                for(int j=l; j<=r; j++) freq[s[j] - 'a']++;
                
                int count = 0;
                for(int j=25; j>=0; j--){
                    count += freq[j];
                    if(count >= k){
                        ans.push_back(j + 'a');
                        break;
                    }
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int q;
        cin>>q;
        vector<vector<string>> queries(q);
        for(int i=0;i<q;i++){
            string x;
            cin>>x;
            if(x=="1"){
                string p,q;
                cin>>p>>q;
                queries[i]={"1",p,q};
            }
            else{
                string p,q,r;
                cin>>p>>q>>r;
                queries[i]={"2",p,q,r};
            }
        }
        Solution ob;
        vector<char> ans=ob.easyTask(n,s,q,queries);
        for(auto ch:ans){
            cout<<ch<<" ";
        }
        cout<<endl;
    }
}

// } Driver Code Ends