#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--){
	    int n,k;
	    cin>>n>>k;
	    deque<int> dq;
	    for (int i=1;i<=n;i++) dq.push_back(i);
	    
	    while(dq.size() > k){
	        int i=0,j=0;
	        while(i<k){
	            if(dq.size() == 1) break;
	            dq.pop_front(); 
	            i++;
	        }
	        while(j<k){
	            if(dq.size() == 1) break;
	            dq.pop_back();
	            j++;
	        } 
	        //cout<<dq.size()<<"\n";
	    }
	    cout<<dq.back()<<"\n";   
	}
	
	return 0;
}