//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
int solve(string str, char ch){
    int n = str.length();
    int curr = 0;
    for(int i=0; i<n; i++){
        if(str[i] == ch){
            curr++;
            while(i<n and str[i+1] == ch) i++;
        }
    }
    return curr;
}


int minSteps(string str) {
    int cona = 0, conb = 0;
    cona = solve(str, 'a');
    conb = solve(str, 'b');
    // cout<<cona<<" "<<conb<<"\n";
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