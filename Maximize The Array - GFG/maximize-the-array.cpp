// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
public:
    vector<int> maximizeArray(int arr1[], int arr2[], int n) {
            // sort(arr1,arr1+n,greater<int>());
            // sort(arr2,arr2+n,greater<int>());
            
            // vector<int> ans(n);
            // unordered_set<int> s;
            // int i = 0, j = 0, k = 0;
            // while(i<n and j<n){
            //     if(k>=n) break;
                    
            //     if(arr1[i] > arr2[j])
            //         ans[k] = arr1[i] , i++;
            //     else
            //         ans[k] = arr2[j] , j++;
            //     k++;
            // }
            // while(k<n){
            //     if(i<n){
            //         ans[k++] = arr1[i++];
            //     }
            //     else if(j<n){
            //         ans[k++] = arr2[j++];
            //     }
            // }
            // return ans;
            
            unordered_set<int> set;
            vector<int> all;
            
            for(int i=0; i<n; i++)
            {
                all.push_back(arr1[i]);
                all.push_back(arr2[i]);
            }
            sort(all.begin(), all.end(), greater<int>());
            for (int i=0; i<n+n && set.size()<n; i++)
            {
                set.insert(all[i]);
            }
            vector<int> max;
            for(int i=0; i<n ; i++)
            {
                if(set.find(arr2[i])!=set.end())
                {
                    max.push_back(arr2[i]);
                    set.erase(set.find(arr2[i]));
                    
                }
            }
            for(int i=0; i<n;i++)
            {
                if(set.find(arr1[i])!=set.end())
                {
                    max.push_back(arr1[i]);
                    set.erase(set.find(arr1[i]));
                }
            }
            return max;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr1[n], arr2[n];
        for (i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        for (i = 0; i < n; i++) {
            cin >> arr2[i];
        }
        Solution ob;
        auto ans = ob.maximizeArray(arr1, arr2, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends