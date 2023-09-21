//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    typedef long long ll;
  
    ll merge(ll low, ll mid, ll high, ll *arr){
        ll i = low, j = mid + 1 , count = 0;
        vector<ll> temp;
        while(i <= mid and j <= high){
            if(arr[i] <= arr[j]){
                temp.push_back(arr[i]);
                i++;
            }
            else{
                temp.push_back(arr[j]);
                count += (mid - i + 1);
                j++;
            }
        }
        while(i <= mid) temp.push_back(arr[i++]);
        while(j <= high) temp.push_back(arr[j++]);
    
        for(i=low; i<=high; i++) arr[i] = temp[i - low];
        return count;
    }
    ll mergeSort(ll low, ll high, ll *arr){
        ll count = 0;
        if(low >= high) return count;
        ll mid = low + (high - low) / 2;
        count += mergeSort(low, mid, arr);
        count += mergeSort(mid+1, high, arr);
        count += merge(low, mid, high, arr);
        return count;
    }
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int inversionCount(long long arr[], long long n)
    {
        return mergeSort(0, n-1, arr);
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends