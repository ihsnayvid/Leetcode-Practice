//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool isSubsequence(string t, string s) {
        if(t[0] != s[0]) return false;
        if(t == "") return true;
        int i = 0, j = 0;
        while(i < s.size()){
            if(s[i] == t[j])
                j++;
            if(j == t.size()) return true;
            i++;
        }
        cout<<t<<" -> "<<s<<"\n";
        return false;
    }
    vector<string> CamelCase(int n, vector<string> dict, string pat) {
        vector<string> ans;
        for(auto &i: dict){
            string s = "";
            for(auto &j: i){
                if(isupper(j)){
                    s += j;
                    if(s == pat){
                        ans.push_back(i);
                        break;
                    }
                }
            }
        }
        if(ans.empty()) ans.push_back("-1");
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> Dictionary(N);
        for (int i = 0; i < N; i++) cin >> Dictionary[i];
        string Pattern;
        cin >> Pattern;
        Solution ob;
        vector<string> ans = ob.CamelCase(N, Dictionary, Pattern);
        sort(ans.begin(), ans.end());
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends