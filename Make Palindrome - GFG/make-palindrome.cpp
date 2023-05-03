//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    bool isPal(string &s){
        for(int i=0, j=s.length()-1; i<j; i++, j--){
            if(s[i] != s[j]) return false;
        }
        return true;
    }
    bool makePalindrome(int n,vector<string> &arr){
        unordered_map<string, int> mp;
        for(auto &i: arr) mp[i]++;
        int c = 0;
        bool pal = false;
        for(auto &i: arr){
            // if(isPal(i)){
            //     pal = true;
            //     c++;
            // }
            string x = i;
            reverse(x.begin(), x.end());
            if(mp.find(x) != mp.end()){
                mp[i]--;
                if(mp[i] == 0) mp.erase(i);
                mp[x]--;
                if(mp[x] == 0) mp.erase(x);
            }
        }
        if(mp.size() == 1){
            string s = mp.begin()->first;
            if(isPal(s)) return true;
        }
        else if(mp.size() == 0) return true;
        return false;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        if(ob.makePalindrome(n,arr)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
// } Driver Code Ends