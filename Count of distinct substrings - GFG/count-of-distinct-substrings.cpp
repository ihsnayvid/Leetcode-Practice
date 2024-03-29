//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

int countDistinctSubstring(string s);

int main()
{
 int t,l,i,j;
 int temp;
    cin>>t;
 while(t--){
 string s;
  cin>>s;
  cout<<countDistinctSubstring(s)<<endl;

 }
}


// } Driver Code Ends

struct Node{
    Node* links[26];
    bool flag;

    bool containsKey(char ch){
        return links[ch - 'a'] != NULL;
    }

    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    }

    Node* get(char ch){
        return links[ch - 'a'];
    }

    void setEnd(){
        flag = true;
    }
    
    bool isEnd(){
        return flag;
    }
};

/*You are required to complete this method */
int countDistinctSubstring(string s)
{
    Node* root = new Node();
    int count = 1;
    
    for(int i=0; i<s.size(); i++){
        Node* node = root;
        for(int j = i; j<s.size(); j++){
            if(!node->containsKey(s[j])){
                node->put(s[j], new Node());
                count++;
            }
            node = node->get(s[j]);
        }
    }
    return count;
}