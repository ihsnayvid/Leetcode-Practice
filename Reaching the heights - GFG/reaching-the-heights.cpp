// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


vector<int> reaching_height(int n, int a[]) ;

int main() {
	int t;
	cin >> t;
	while (t-- > 0) {
	    int n; 
	    cin >> n;
	    int a[n];
	    for (int i = 0; i < n; i++) 
	        cin >> a[i];
	    vector<int> v;
	    v = reaching_height(n,a);
	
	    if(v.size()==1 and v[0] == -1){
	        cout << "Not Possible\n";
	    }
	    else{
	    for(int i:v)
	        cout << i << " ";
	    cout << endl;}
	    
	}
	return 0;
}// } Driver Code Ends


//User function Template for C++

vector<int> reaching_height(int n, int a[]) {
    sort(a, a+n);
    vector<int> ans;
    int i = 0, j = n-1, k = 0, sum = 0;
    while(i<=j){
        //cout<<"\nk = "<<k<<" sum = "<<sum;
        if(k&1){
            ans.push_back(a[i]);
            sum -= a[i];
            i++;
        }
        else{
            ans.push_back(a[j]);
            sum += a[j];
            j--;
        }
        k++;
    }
    //cout<<sum<<"\n";
    if(sum == 0) return {-1};
    return ans;
}
