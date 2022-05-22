// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    string findAndReplace(string s ,int q, int index[], string sources[], string targets[]) {
        string str = s;
        for(int i=0; i<q; i++){
            int j = index[i];
            string si = sources[i];
            string toCheck = s.substr(j, sources[i].length());
            if(si == toCheck){
                int idxChange = str.length() - s.length();
                str.replace(j + idxChange, sources[i].length(), targets[i]);
            }
        }
        return str;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        
        int Q;
        cin>>Q;
        int index[Q];
        string sources[Q], targets[Q];
        
        for(int i=0; i<Q; i++)
            cin>>index[i];
        for(int i=0; i<Q; i++)
            cin>>sources[i];
        for(int i=0; i<Q; i++)
            cin>>targets[i];

        Solution ob;
        cout<<ob.findAndReplace(S,Q,index,sources,targets)<<endl;
    }
    return 0;
}  // } Driver Code Ends