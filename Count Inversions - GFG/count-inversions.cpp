//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
  
    long long merge(long long low, long long mid, long long high, long long v[], long long *arr){
        long long i = low, j = mid, k = low;
        long long count = 0;
        while(i < mid and j <= high){
            if(arr[j] < arr[i]){
                count += (mid-i);
                v[k++] = arr[j++];
            }
            else{
                v[k++] = arr[i++];
            }
        }
        
        while(i < mid){
            v[k++] = arr[i++];
        }
        
        while(j <= high){
            v[k++] = arr[j++];
        }
        for(int i=low; i<= high; i++){
            arr[i] = v[i];
        }
        return count;
    }
    long long mergeSort(long long low, long long high, long long v[], long long *arr){
        long long count = 0;
        if(low < high){
            int mid = low + (high - low) / 2;
            count += mergeSort(low, mid, v, arr);
            count += mergeSort(mid+1, high, v, arr);
            
            count += merge(low, mid+1, high, v, arr);
        }
        return count;
    }
  
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int inversionCount(long long arr[], long long n)
    {
        long long i = 0, j = n-1;
        long long v[n];
        return mergeSort(i, j, v, arr);
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