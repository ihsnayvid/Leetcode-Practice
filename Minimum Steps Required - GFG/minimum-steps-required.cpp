//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

int minSteps(string str) {
    int n = str.length();
    int cona = 0, conb = 0;
  
    for(int i=0; i<n; i++){
        if(str[i] == 'a'){
            cona++;
            while(i<n and str[i+1] == 'a') i++;
        }
        if(str[i] == 'b'){
            conb++;
            while(i<n and str[i+1] == 'b') i++;
        }
    }
    
    return min(cona, conb) + 1;
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << minSteps(str) << endl;
    }
}

// } Driver Code Ends