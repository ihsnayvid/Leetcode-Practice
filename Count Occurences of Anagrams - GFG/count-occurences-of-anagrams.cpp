// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    int i = 0, j = 0, count = 0;
        int n = txt.size(), k = pat.size();
        vector<int>v(26);
        vector<int>freq(26);
        for(int x=0;x<k;x++)
            freq[pat[x]-'a']++;
        
        while(j < n){
            if(j-i+1 <= k)
                v[txt[j]-'a']++; 
        
            if(j-i+1 == k){
                if(v == freq)
                    count++;
                v[txt[i]-'a']--;
                i++;
            }
            j++;
        }
        return count;
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends